#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    auto oob = [&](int x, int y) {
        return x < 0 || x >= n || y < 0 || y >= n;
    };

    vector<vector<int>> vst(n, vector<int>(n, -1));
    bool poss = true;
    const int dx[] = {-1, -1, 0, 0, 1, 1};
    const int dy[] = {0, 1, -1, 1, -1, 0};
    function<int(int, int, int)> dfs = [&](int x, int y, int v) {
        int cnt = 1;
        vst[x][y] = v;
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (oob(nx, ny) || grid[nx][ny] != 'X') continue;
            if (vst[nx][ny] < 0) cnt += dfs(nx, ny, 1 - v);
            else if (vst[nx][ny] == v) poss = false;
        }
        return cnt;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'X' && vst[i][j] < 0) ans = max(ans, min(2, dfs(i, j, 0)));
        }
    }
    if (!poss) ans = 3;
    cout << ans << '\n';
}