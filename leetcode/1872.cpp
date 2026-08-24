class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for (int i = 1; i < n; i++) stones[i] += stones[i - 1];

        int mx = stones[n - 1];
        for (int i = n - 2; i; i--) {
            int cur = stones[i] - mx;
            if (cur > mx) mx = cur;
        }

        return mx;
    }
};