class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), sz = n + m + 1;
        vector<vector<bool>> conn(m + 1, vector<bool>(sz, false));
        conn[1][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i - 1][j - 1] == '(') {
                    for (int k = sz - 2; k >= 0; k--) conn[j][k + 1] = conn[j - 1][k] || conn[j][k];
                    conn[j][0] = false;
                } else {
                    for (int k = 1; k < sz; k++) conn[j][k - 1] = conn[j - 1][k] || conn[j][k];
                    conn[j][sz - 2] = false;
                }
            }
        }
        return conn[m][0];
    }
};