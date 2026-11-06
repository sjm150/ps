class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<vector<int>> t(n);
        int mx = 0;
        for (auto &log: logs) {
            t[log[0] - 1].push_back(log[1]);
            mx = max(mx, log[1]);
        }

        int sz = max(mx, *max_element(queries.begin(), queries.end())) + 1;
        vector<int> cnt(sz, 0);
        for (auto &t: t) {
            t.push_back(0);
            t.push_back(sz);
            sort(t.begin(), t.end());
            int tsz = t.size();
            for (int i = 0; i < tsz - 1; i++) {
                if (t[i + 1] - t[i] > x + 1) {
                    cnt[t[i] + 1]++;
                    cnt[t[i + 1] - x]--;
                }
            }
        }
        for (int i = 1; i < sz; i++) cnt[i] += cnt[i - 1];

        vector<int> ans;
        for (int q: queries) ans.push_back(cnt[max(0, q - x)]);
        return ans;
    }
};