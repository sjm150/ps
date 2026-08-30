class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), l = min_element(nums.begin(), nums.end()) - nums.begin(), r = max_element(nums.begin(), nums.end()) - nums.begin();
        if (l > r) swap(l, r);
        return min(r + 1, min(n - l, n - r + l + 1));
    }
};