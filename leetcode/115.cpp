class Solution {
public:
    int numDistinct(string s, string t) {
        const long long mx = 1e10;
        int n = t.size();
        vector<long long> cnt(n + 1, 0);
        cnt[0] = 1;
        for (char c: s) {
            for (int i = n - 1; i >= 0; i--) {
                if (c == t[i]) cnt[i + 1] = min(mx, cnt[i + 1] + cnt[i]);
            }
        }
        return cnt[n];
    }
};