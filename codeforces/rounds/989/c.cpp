#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> grid(n);
        for (auto &s: grid) cin >> s;
        vector<vector<bool>> ok(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'L') {
                ok[i][0] = true;
                q.emplace(i, 0);
            }
            if (grid[i][m - 1] == 'R') {
                ok[i][m - 1] = true;
                q.emplace(i, m - 1);
            }
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'U') {
                ok[0][j] = true;
                q.emplace(0, j);
            }
            if (grid[n - 1][j] == 'D') {
                ok[n - 1][j] = true;
                q.emplace(n - 1, j);
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || ok[nx][ny]) continue;
                char c = grid[nx][ny];
                if ((c == 'U' && dx[i] == 1) || (c == 'D' && dx[i] == -1) || (c == 'L' && dy[i] == 1) || (c == 'R' && dy[i] == -1)) {
                    ok[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '?') continue;
                bool blk = true;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (!ok[nx][ny]) {
                        blk = false;
                        break;
                    }
                }
                if (blk) ok[i][j] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!ok[i][j]) ans++;
            }
        }
        cout << ans << '\n';
    }
}