class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prd = 1;
        for (int i = n; i; i /= 10) {
            sum += i % 10;
            prd *= i % 10;
        }
        return n % (sum + prd) == 0;
    }
};