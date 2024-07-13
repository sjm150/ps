#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> col(n);
    for (auto &col: col) {
        for (int i = 0; i < m; i++) {
            char c; cin >> c;
            if (c == '1') col.push_back(i);
        }
    }

    int ans = 0;
    for (int j = 0; j < m; j++) {
        vector<pair<int, int>> stk;
        for (int i = 0; i < n; i++) {
            int idx = upper_bound(col[i].begin(), col[i].end(), j) - col[i].begin() - 1;
            if (idx >= 0) {
                while (!stk.empty() && stk.back().second <= col[i][idx]) stk.pop_back();
                stk.emplace_back(i, col[i][idx]);
            }
            if (!stk.empty()) {
                ans = max(ans, (i + 1) * (j - stk[0].second));
                ans = max(ans, (i - stk.back().first) * (j + 1));
            } else {
                ans = max(ans, (i + 1) * (j + 1));
            }
            for (int k = 1; k < stk.size(); k++) {
                ans = max(ans, (i - stk[k - 1].first) * (j - stk[k].second));
            }
        }
    }

    cout << ans << '\n';
}