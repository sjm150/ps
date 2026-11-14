class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        const int inf = 1e9;
        int n = nums.size(), mn = inf;
        for (int i = l; i <= r; i++) {
            int sum = 0;
            for (int j = 0; j < i - 1; j++) sum += nums[j];
            for (int j = i - 1; j < n; j++) {
                sum += nums[j];
                if (sum > 0) mn = min(mn, sum);
                sum -= nums[j - i + 1];
            }
        }
        return mn < inf ? mn : -1;
    }
};