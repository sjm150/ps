class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int o = 0, e = 1, p = 0, cnt = 0;
        for (int a: arr) {
            p += a;
            if (p % 2) {
                cnt += e;
                o++;
            } else {
                cnt += o;
                e++;
            }
            if (cnt >= mod) cnt -= mod;
        }
        return cnt;
    }
};