class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        sort(items.begin(), items.end(), [](auto &a, auto &b){ return a[1] < b[1]; });
        int n = items.size();
        vector<int> fc(n + 1, 0);
        for (auto &item: items) fc[item[0]]++;
        for (int i = 1; i <= n; i++) {
            for (int j = i * 2; j <= n; j += i) fc[i] += fc[j];
        }

        int sum = 0, mnp = items[0][1];
        for (auto &item: items) {
            int f = item[0], p = item[1];
            if (p > mnp * 2) break;
            int cnt = min(fc[f] - 1, budget / p);
            budget -= cnt * p;
            sum += cnt * 2;
        }
        return sum + budget / mnp;
    }
};