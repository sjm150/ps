#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> grid(n);
        for (auto &g: grid) cin >> g;
        vector<vector<bool>> vst(n, vector<bool>(n, false));
        function<void(int, int)> dfs = [&](int x, int y) {
            vst[x][y] = true;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = x + dx, ny = y + dy;
                    if (0 <= nx && nx < n && 0 <= ny && ny < n && !vst[nx][ny] && grid[nx][ny] != 'b') dfs(nx, ny);
                }
            }
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vst[i][j] && grid[i][j] == 'w') dfs(i, j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vst[i][j] && grid[i][j] == '-') ans++;
            }
        }
        cout << ans << '\n';
    }
}