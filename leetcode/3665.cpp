class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int mod = 1e9 + 7;
        int n = grid.size(), m = grid[0].size();
        vector<vector<array<int, 2>>> cnt(n + 1, vector<array<int, 2>>(m + 1, {0, 0}));
        cnt[1][1][0] = cnt[1][1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i - 1][j - 1]) {
                    cnt[i][j][0] = cnt[i][j - 1][1];
                    cnt[i][j][1] = cnt[i - 1][j][0];
                } else {
                    cnt[i][j][0] = cnt[i][j][1] = (cnt[i][j][0] + cnt[i - 1][j][0] + cnt[i][j - 1][1]) % mod;
                }
            }
        }
        return cnt[n][m][0];
    }
};