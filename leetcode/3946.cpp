class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> sum(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (items[j][0] % items[i][0] == 0) sum[i]++;
            }
        }

        vector<int> cnt(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = budget; j >= items[i][1]; j--) cnt[j] = max(cnt[j], cnt[j - items[i][1]] + sum[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = items[i][1]; j <= budget; j++) cnt[j] = max(cnt[j], cnt[j - items[i][1]] + 1);
        }
        return *max_element(cnt.begin(), cnt.end());
    }
};