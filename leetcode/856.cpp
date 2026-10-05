class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> stk;
        int cur = 0;
        for (char c: s) {
            if (c == '(') {
                stk.push_back(cur);
                cur = 0;
            } else {
                cur = stk.back() + (cur ? cur * 2 : 1);
                stk.pop_back();
            }
        }
        return cur;
    }
};