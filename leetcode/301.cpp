class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size(), o = 0, c = 0;
        for (char a: s) {
            if (a == '(') {
                o++;
            } else if (a == ')') {
                if (o) o--;
                else c++;
            }
            
        }

        vector<string> res;
        int sz = 1 << n;
        for (int i = 0; i < sz; i++) {
            if (__builtin_popcount(i) != n - o - c) continue;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (!((i >> j) & 1)) continue;
                if (s[j] == '(') {
                    cnt++;
                } else if (s[j] == ')') {
                    cnt--;
                    if (cnt < 0) break;
                }
            }
            if (cnt == 0) {
                res.emplace_back();
                for (int j = 0; j < n; j++) {
                    if ((i >> j) & 1) res.back() += s[j];
                }
            }
        }

        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end()) - res.begin());
        return res;
    }
};