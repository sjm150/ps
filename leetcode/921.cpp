class Solution {
public:
    int minAddToMakeValid(string s) {
        int cur = 0, cnt = 0;
        for (char c: s) {
            if (c == '(') cur++;
            else if (cur) cur--;
            else cnt++;
        }
        return cur + cnt;
    }
};