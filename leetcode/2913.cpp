class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end()), sum = 0;
        vector<int> cnt(mx + 1);
        for (int i = 0; i < n; i++) {
            int d = 0;
            fill(cnt.begin(), cnt.end(), 0);
            for (int j = i; j < n; j++) {
                if (cnt[nums[j]] == 0) d++;
                cnt[nums[j]]++;
                sum += d * d;
            }
        }
        return sum;
    }
};