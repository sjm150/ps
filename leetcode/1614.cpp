class Solution {
public:
    int maxDepth(string s) {
        int mx = 0, cnt = 0;
        for (char c: s) {
            if (c == '(') {
                cnt++;
                mx = max(mx, cnt);
            } else if (c == ')') {
                cnt--;
            }
        }
        return mx;
    }
};