typedef pair<int, int> pi;
typedef tuple<int, int, int, int> ti4;
typedef long long ll;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<ti4> lrwi;
        for (int i = 0; i < n; i++) lrwi.emplace_back(intervals[i][0], intervals[i][1], intervals[i][2], i);
        sort(lrwi.begin(), lrwi.end());

        vector<vector<ll>> sum(n, vector<ll>(4, 0));
        vector<vector<vector<int>>> pth(n, vector<vector<int>>(4));
        vector<int> mxi(4, -1);
        vector<priority_queue<pi, vector<pi>, greater<pi>>> pqs(4);
        auto upd = [&](int j, int lim) {
            while (!pqs[j].empty() && pqs[j].top().first < lim) {
                int i = pqs[j].top().second;
                pqs[j].pop();
                if (mxi[j] < 0 || sum[mxi[j]][j] < sum[i][j] || (sum[mxi[j]][j] == sum[i][j] && pth[mxi[j]][j] > pth[i][j])) mxi[j] = i;
            }
        };

        for (auto [l, r, w, i]: lrwi) {
            for (int j = 3; j; j--) {
                upd(j - 1, l);
                if (mxi[j - 1] < 0) continue;
                sum[i][j] = sum[mxi[j - 1]][j - 1] + w;
                pth[i][j] = pth[mxi[j - 1]][j - 1];
                pth[i][j].push_back(i);
                sort(pth[i][j].begin(), pth[i][j].end());
                pqs[j].emplace(r, i);
            }
            sum[i][0] = w;
            pth[i][0] = {i};
            pqs[0].emplace(r, i);
        }

        ll mx = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                if (mx < sum[i][j]) {
                    mx = sum[i][j];
                    ans = pth[i][j];
                } else if (mx == sum[i][j] && ans > pth[i][j]) {
                    ans = pth[i][j];
                }
            }
        }

        return ans;
    }
};