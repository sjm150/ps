class Solution {
public:
    int minimizeSum(vector<int>& a) {
        const int inf = 1e9 + 7;
        int mx[3] = {-inf, -inf, -inf}, mn[3] = {inf, inf, inf};
        for (int a: a) {
            if (mx[0] < a) mx[2] = mx[1], mx[1] = mx[0], mx[0] = a;
            else if (mx[1] < a) mx[2] = mx[1], mx[1] = a;
            else if (mx[2] < a) mx[2] = a;
            if (mn[0] > a) mn[2] = mn[1], mn[1] = mn[0], mn[0] = a;
            else if (mn[1] > a) mn[2] = mn[1], mn[1] = a;
            else if (mn[2] > a) mn[2] = a;
        }
        return min(mx[2] - mn[0], min(mx[0] - mn[2], mx[1] - mn[1]));
    }
};