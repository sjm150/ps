class Solution {
public:
    int maxLength(vector<int>& nums) {
        const int p[4] = {2, 3, 5, 7};
        int n = nums.size(), mx = 2;
        for (int i = 0; i < n; i++) {
            vector<bool> used(4, false);
            int j = i;
            for (; j < n; j++) {
                bool ok = true;
                for (int k = 0; k < 4; k++) {
                    if (nums[j] % p[k]) continue;
                    if (used[k]) {
                        ok = false;
                        break;
                    } else {
                        used[k] = true;
                    }
                }
                if (!ok) break;
            }
            mx = max(mx, j - i);
        }
        return mx;
    }
};