class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> used(201, false);
        for (int a: nums) used[a] = true;
        int ans = k;
        while (used[ans]) ans += k;
        return ans;
    }
};