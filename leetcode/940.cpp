class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod = 1e9 + 7;
        vector<int> cnt(26, 0);
        int sum = 1;
        for (char c: s) {
            int cur = (sum - cnt[c - 'a'] + mod) % mod;
            cnt[c - 'a'] = (cnt[c - 'a'] + cur) % mod;
            sum = (sum + cur) % mod;
        }
        return (sum + mod - 1) % mod;
    }
};