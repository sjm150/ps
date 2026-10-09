class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(), cnt = 0, req = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cnt++;
            } else if (i + 1 < n && s[i + 1] == ')') {
                if (cnt) cnt--;
                else req++;
                i++;
            } else {
                req++;
                if (cnt) cnt--;
                else req++;
            }
        }
        return cnt * 2 + req;
    }
};