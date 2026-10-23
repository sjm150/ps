class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        const int mx = (1 << 30) - 1;
        int n = nums.size(), k = mx;
        for (int i = 0; i < n; i++) {
            if (i != nums[i]) k &= nums[i];
        }
        return k < mx ? k : 0;
    }
};