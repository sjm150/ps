class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), tot = accumulate(nums.begin(), nums.end(), 0), mx = -1;
        for (int l = 0, r = 0, sum = 0; r < n; r++) {
            sum += nums[r];
            while (l <= r && sum > tot - x) sum -= nums[l++];
            if (sum == tot - x) mx = max(mx, r - l + 1);
        }
        return mx < 0 ? -1 : n - mx;
    }
};