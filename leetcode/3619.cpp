typedef long long ll;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vst(n, vector<bool>(m, false));
        function<ll(int, int)> dfs = [&](int x, int y) {
            vst[x][y] = true;
            ll ret = grid[x][y];
            for (auto [dx, dy]: {make_pair(-1, 0), {1, 0}, {0, -1}, {0, 1}}) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || !grid[nx][ny] || vst[nx][ny]) continue;
                ret += dfs(nx, ny);
            }
            return ret;
        };

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && !vst[i][j] && dfs(i, j) % k == 0) cnt++;
            }
        }
        return cnt;
    }
};