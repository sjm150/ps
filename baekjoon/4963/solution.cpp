#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        int w, h;
        cin >> w >> h;
        if (!w) break;
        vector<vector<int>> grid(h, vector<int>(w));
        for (auto &g: grid) {
            for (int &g: g) cin >> g;
        }
        vector<vector<bool>> vst(h, vector<bool>(w, false));
        function<void(int, int)> dfs = [&](int x, int y) {
            vst[x][y] = true;
            for (auto [dx, dy]: {make_pair(-1, 0), {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}}) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || !grid[nx][ny] || vst[nx][ny]) continue;
                dfs(nx, ny);
            }
        };
        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (vst[i][j] || !grid[i][j]) continue;
                dfs(i, j);
                ans++;
            }
        }
        cout << ans << '\n';
    }
}