class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for (char c: s) {
            if (c == '(') {
                stk.push_back(')');
            } else if (c == '{') {
                stk.push_back('}');
            } else if  (c == '[') {
                stk.push_back(']');
            } else {
                if (stk.empty() || stk.back() != c) return false;
                stk.pop_back();
            }
        }
        return stk.empty();
    }
};