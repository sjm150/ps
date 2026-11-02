typedef long long ll;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return accumulate(nums.begin(), nums.end(), 0, [&](int acc, int a){ return acc + abs(a - nums[n / 2]); });
    }
};