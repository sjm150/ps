class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> len;
        int mx = 1;
        for (int a: nums) {
            len[a + 1] = max(len[a + 1], len[a] + 1);
            len[a] = max(len[a], len[a - 1] + 1);
            mx = max(mx, max(len[a], len[a + 1]));
        }
        return mx;
    }
};