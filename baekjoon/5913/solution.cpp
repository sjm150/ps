#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

const int n = 5;
vector<vector<bool>> blk(n, vector<bool>(n, false));
int mxd, ans;

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

void dfs(int jx, int jy, int jb, int hx, int hy, int hb, int d) {
    if (jx == hx && jy == hy) {
        if (d == mxd) ans++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int njx = jx + dx[i];
        int njy = jy + dy[i];
        int njb = 1 << (njx * 5 + njy);
        if (oob(njx, njy) || blk[njx][njy] || (jb & njb) || (hb & njb)) continue;

        for (int j = 0; j < 4; j++) {
            int nhx = hx + dx[j];
            int nhy = hy + dy[j];
            int nhb = 1 << (nhx * 5 + nhy);
            if (oob(nhx, nhy) || blk[nhx][nhy] || (jb & nhb) || (hb & nhb)) continue;

            dfs(njx, njy, jb | njb, nhx, nhy, hb | nhb, d + 1);
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k; cin >> k;
    mxd = (n * n - k) / 2;
    while (k--) {
        int x, y; cin >> x >> y;
        --x, --y;
        blk[x][y] = true;
    }
    dfs(0, 0, 1, 4, 4, 1 << 24, 0);
    cout << ans << '\n';
}