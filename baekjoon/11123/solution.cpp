#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int h, w; cin >> h >> w;
        vector<string> grid(h);
        for (auto &s: grid) cin >> s;
        vector<vector<bool>> vst(h, vector<bool>(w, false));
        pair<int, int> d[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        function<void(int, int)> dfs = [&](int x, int y) {
            vst[x][y] = true;
            for (auto [dx, dy]: d) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || grid[nx][ny] == '.' || vst[nx][ny]) continue;
                dfs(nx, ny);
            }
        };
        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == '#' && !vst[i][j]) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}