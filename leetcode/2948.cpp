class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> ord(n);
        for (int i = 0; i < n; i++) ord[i] = {nums[i], i};
        sort(ord.begin(), ord.end());

        vector<int> gi;
        for (int i = 0; i < n; i++) {
            auto [num, idx] = ord[i];
            if (i == 0 || num - ord[i - 1].first > limit) gi.push_back(i);
            nums[idx] = gi.size() - 1;
        }

        for (int &num: nums) num = ord[gi[num]++].first;
        return nums;
    }
};