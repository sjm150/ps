#include <bits/stdc++.h>
using namespace std;

int sz;
int a[2][64][64];
int cur, nxt = 1;

void tor(int l) {
    for (int i = 0; i < sz; i += l) {
        for (int j = 0; j < sz; j += l) {
            for (int ii = 0; ii < l; ii++) {
                for (int jj = 0; jj < l; jj++) {
                    a[nxt][i + jj][j + l - 1 - ii] = a[cur][i + ii][j + jj];
                }
            }
        }
    }
    swap(cur, nxt);
}

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

bool oob(int x, int y) {
    return x < 0 || x >= sz || y < 0 || y >= sz;
}

void fire() {
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (oob(ni, nj)) continue;
                if (a[cur][ni][nj]) cnt++;
            }
            if (cnt < 3) a[nxt][i][j] = max(0, a[cur][i][j] - 1);
            else a[nxt][i][j] = a[cur][i][j];
        }
    }
    swap(cur, nxt);
}

bool vst[64][64];

int dfs(int x, int y) {
    vst[x][y] = true;
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (vst[nx][ny] || oob(nx, ny) || a[cur][nx][ny] == 0) continue;
        ret += dfs(nx, ny);
    }
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    sz = 1 << n;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            cin >> a[0][i][j];
            a[1][i][j] = a[0][i][j];
        }
    }
    while (q--) {
        int l; cin >> l;
        tor(1 << l);
        fire();
    }

    int sum = 0, cnt = 0;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            sum += a[cur][i][j];
            if (!vst[i][j] && a[cur][i][j]) cnt = max(cnt, dfs(i, j));
        }
    }
    cout << sum << '\n' << cnt << '\n';
}