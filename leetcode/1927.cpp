class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sum = 0, cnt = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') cnt++;
            else sum += num[i] - '0';
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') cnt--;
            else sum -= num[i] - '0';
        }
        return abs(cnt) % 2 || sum * 2 != -9 * cnt;
    }
};