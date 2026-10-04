class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(), ocnt = count(s.begin(), s.end(), '('), ccnt = count(s.begin(), s.end(), ')'), acnt = count(s.begin(), s.end(), '*');
        int d = abs(ocnt - ccnt);
        if (acnt < d) return false;
        int r = (acnt - d) / 2, o = ocnt < ccnt ? d + r : r, c = ocnt > ccnt ? d + r : r;

        for (int i = 0; o && i < n; i++) {
            if (s[i] == '*') {
                s[i] = '(';
                o--;
            }
        }
        for (int i = n - 1; c && i >= 0; i--) {
            if (s[i] == '*') {
                s[i] = ')';
                c--;
            }
        }

        int cnt = 0;
        for (char c: s) {
            if (c == '(') {
                cnt++;
            } else if (c == ')') {
                if (cnt) cnt--;
                else return false;
            }
        }
        return cnt == 0;
    }
};