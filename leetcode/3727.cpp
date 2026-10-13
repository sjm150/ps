class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int &a: nums) a = a * a;
        sort(nums.begin(), nums.end());
        long long scr = 0;
        for (int i = 0; i < n / 2; i++) scr -= nums[i];
        for (int i = n / 2; i < n; i++) scr += nums[i];
        return scr;
    }
};