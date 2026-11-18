class Solution {
public:
    int minChanges(string s) {
        int cur = 0, cnt = 0;
        for (char c: s) {
            if (c == '0') {
                if (cur <= 0) cur--;
                else if (cur % 2) cur++, cnt++;
                else cur = -1;
            } else {
                if (cur >= 0) cur++;
                else if ((-cur) % 2) cur--, cnt++;
                else cur = 1;
            }
        }
        return cnt;
    }
};