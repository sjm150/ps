#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<bool> conn(n + 1, false);
        vector<tuple<int, int, int>> ans;
        while (m--) {
            int u, v; cin >> u >> v;
            if (u > v) swap(u, v);
            if (u == 1) {
                conn[v] = !conn[v];
            } else {
                conn[u] = !conn[u];
                conn[v] = !conn[v];
                ans.emplace_back(1, u, v);
            }
        }
        int c = -1;
        for (int i = 2; i <= n; i++) {
            if (conn[i]) {
                c = i;
                break;
            }
        }
        if (c > 0) {
            for (int i = 2; i <= n; i++) {
                if (!conn[i]) {
                    ans.emplace_back(1, c, i);
                    c = i;
                }
            }
        }
        cout << ans.size() << '\n';
        for (auto [a, b, c]: ans) cout << a << ' ' << b << ' ' << c << '\n';
    }
}