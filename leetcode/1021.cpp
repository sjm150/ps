class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int cnt = 0;
        for (char c: s) {
            if (c == '(') {
                if (cnt) res += '(';
                cnt++;
            } else {
                cnt--;
                if (cnt) res += ')';
            }
        }
        return res;
    }
};