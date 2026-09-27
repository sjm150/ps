class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> idx;
        string res;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                idx.push_back(res.size());
            } else if (s[i] == ')') {
                reverse(res.begin() + idx.back(), res.end());
                idx.pop_back();
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};