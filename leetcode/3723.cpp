class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) return "";
        string s(num, '0');
        for (int i = 0; i < num; i++) {
            if (sum > 9) {
                s[i] = '9';
                sum -= 9;
            } else {
                s[i] = sum + '0';
                break;
            }
        }
        return s;
    }
};