class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vst(n, vector<bool>(m, false));
        function<bool(int, int)> dfs = [&](int x, int y) {
            vst[x][y] = true;
            bool ret = true;
            for (auto [dx, dy]: {make_pair(-1, 0), {1, 0}, {0, -1}, {0, 1}}) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) ret = false;
                else if (!grid[nx][ny] && !vst[nx][ny]) ret &= dfs(nx, ny);
            }
            return ret;
        };
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j] && !vst[i][j] && dfs(i, j)) cnt++;
            }
        }
        return cnt;
    }
};