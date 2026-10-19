class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        auto l = lower_bound(nums.begin(), nums.end(), target), u = upper_bound(nums.begin(), nums.end(), target);
        vector<int> res(u - l);
        iota(res.begin(), res.end(), l - nums.begin());
        return res;
    }
};