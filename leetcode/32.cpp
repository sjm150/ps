class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ocnt = 0, mcnt = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                ocnt++;
            } else if (ocnt) {
                ocnt--;
                mcnt += 2;
                if (!ocnt && mx < mcnt) mx = mcnt;
            } else {
                ocnt = mcnt = 0;
            }
        }
        ocnt = mcnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') {
                ocnt++;
            } else if (ocnt) {
                ocnt--;
                mcnt += 2;
                if (!ocnt && mx < mcnt) mx = mcnt;
            } else {
                ocnt = mcnt = 0;
            }
        }
        return mx;
    }
};