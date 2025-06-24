#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        int r = -1;
        for (int i = 0; i < n; i++) {
            if (edges[i].size() == 2) {
                r = i;
                break;
            }
        }
        if (r < 0) {
            cout << "NO\n";
            continue;
        }

        vector<pair<int, int>> ans;
        function<void(int, int, bool)> dfs = [&](int pre, int cur, bool r) {
            for (int nxt: edges[cur]) {
                if (nxt == pre) continue;
                dfs(cur, nxt, !r);
            }
            if (r) ans.emplace_back(cur, pre);
            else ans.emplace_back(pre, cur);
        };
        dfs(r, edges[r][0], false);
        dfs(r, edges[r][1], true);

        cout << "YES\n";
        for (auto [u, v]: ans) cout << u + 1 << ' ' << v + 1 << '\n';
    }
}