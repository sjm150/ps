class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const int inf = 1e9;
        vector<int> mn(n + 1, inf);
        mn[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= min(i + 3, n); j++) mn[j] = min(mn[j], mn[i] + costs[j - 1] + (j - i) * (j - i));
        }
        return mn[n];
    }
};