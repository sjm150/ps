class Solution {
public:
    int minOperations(vector<int>& a) {
        const int mx = 1e9;
        int n = a.size();
        if (n == 1) return 0;
        auto asc = [&]() {
            int st = a[n - 1] > a[0] ? 0 : -1;
            for (int i = 1; i < n; i++) {
                if (a[i - 1] > a[i]) {
                    if (st < 0) st = i;
                    else return mx;
                }
            }
            return min(st, n - st + 2);
        };
        auto dsc = [&]() {
            int st = a[n - 1] < a[0] ? 0 : -1;
            for (int i = 1; i < n; i++) {
                if (a[i - 1] < a[i]) {
                    if (st < 0) st = i;
                    else return mx;
                }
            }
            return min(st + 1, n - st + 1);
        };
        int mn = min(asc(), dsc());
        return mn < mx ? mn : -1;
    }
};