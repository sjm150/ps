#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> edges(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        
        vector<bool> used(n, false);
        vector<int> dst(n), p(n);
        vector<pair<int, int>> mx(n);
        function<void(int, int)> dfs = [&](int pre, int cur) {
            mx[cur] = {dst[cur], cur};
            for (int nxt: edges[cur]) {
                if (nxt == pre || used[nxt]) continue;
                p[nxt] = cur;
                dst[nxt] = dst[cur] + 1;
                dfs(cur, nxt);
                mx[cur] = max(mx[cur], mx[nxt]);
            }
        };

        vector<tuple<int, int, int>> ans;
        function<void(int)> solve = [&](int r) {
            p[r] = -1;
            dst[r] = 0;
            dfs(-1, r);

            r = mx[r].second;
            p[r] = -1;
            dst[r] = 0;
            dfs(-1, r);
            
            ans.emplace_back(mx[r].first + 1, max(r, mx[r].second) + 1, min(r, mx[r].second) + 1);
            for (int i = mx[r].second; i != p[r]; i = p[i]) used[i] = true;
            for (int i = mx[r].second; i != p[r]; i = p[i]) {
                for (int nxt: edges[i]) {
                    if (!used[nxt]) solve(nxt);
                }
            }
        };
        solve(0);

        sort(ans.begin(), ans.end(), greater<tuple<int, int, int>>());
        for (auto [d, u, v]: ans) cout << d << ' ' << u << ' ' << v << ' ';
        cout << '\n';
    }
}