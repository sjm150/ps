class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), mx = 0;
        for (int r = - n + 1; r <= n - 1; r++) {
            for (int d = - n + 1; d <= n - 1; d++) {
                int cnt = 0;
                for (int i = max(0, r); max(i, i - r) < n; i++) {
                    for (int j = max(0, d); max(j, j - d) < n; j++) {
                        if (img1[i - r][j - d] && img2[i][j]) cnt++;
                    }
                }
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};