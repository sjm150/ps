class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<set<string>> s(n + 1);
        s[0].insert("");
        for (int i = 1; i <= n; i++) {
            for (auto &s1: s[i - 1]) s[i].insert("(" + s1 + ")");
            for (int j = 1; j < i; j++) {
                for (auto &s1: s[j]) {
                    for (auto &s2: s[i - j]) s[i].insert(s1 + s2);
                }
            }
        }
        vector<string> res(s[n].begin(), s[n].end());
        return res;
    }
};