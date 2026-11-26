class Solution {
public:
    bool canAliceWin(int n) {
        for (int i = 10; i; i -= 2) {
            if (n < i) return false;
            else n -= i;
            if (n < i - 1) return true;
            else n -= i - 1;
        }
        return false;
    }
};