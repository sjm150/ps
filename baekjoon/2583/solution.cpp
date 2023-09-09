#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int m, n;
bool drwn[100][100];
bool vst[100][100];

int dfs(int x, int y) {
    vst[x][y] = true;
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < m && 0 <= ny && ny < n
            && !drwn[nx][ny] && !vst[nx][ny]) {
            ret += dfs(nx, ny);
        }
    }
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k; cin >> m >> n >> k;
    while (k--) {
        int xs, ys, xe, ye;
        cin >> xs >> ys >> xe >> ye;
        for (int i = ys; i < ye; i++) {
            for (int j = xs; j < xe; j++) {
                drwn[i][j] = true;
            }
        }
    }
    vector<int> area;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!drwn[i][j] && !vst[i][j]) area.push_back(dfs(i, j));
        }
    }
    sort(area.begin(), area.end());
    cout << area.size() << '\n';
    for (int a: area) cout << a << ' ';
    cout << '\n';
}