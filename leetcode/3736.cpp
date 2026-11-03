class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        return accumulate(nums.begin(), nums.end(), 0, [&](int acc, int a){ return acc + mx - a; });
    }
};