class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int mx = 1024;
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool>>> conn(n + 1, vector<vector<bool>>(m + 1, vector<bool>(mx, false)));
        conn[1][1][grid[0][0]] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < mx; k++) {
                    if (conn[i][j + 1][k ^ grid[i][j]] || conn[i + 1][j][k ^ grid[i][j]]) {
                        conn[i + 1][j + 1][k] = true;
                    }
                }
            }
        }
        return find(conn[n][m].begin(), conn[n][m].end(), true) - conn[n][m].begin();
    }
};