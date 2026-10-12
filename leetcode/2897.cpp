class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int mxb = 1 << 30, mod = 1e9 + 7;
        vector<int> sel(k, 0);
        for (int b = 1; b < mxb; b <<= 1) {
            int cnt = 0;
            for (int a: nums) {
                if (cnt == k) break;
                if (a & b) cnt++;
            }
            for (int i = 0; i < cnt; i++) sel[i] |= b;
        }
        return accumulate(sel.begin(), sel.end(), 0, [](int acc, int a){
            return (acc + (long long)(a) * a) % mod;
        });
    }
};