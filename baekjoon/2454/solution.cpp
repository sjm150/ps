#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int ans = 0;
    function<int(int, int)> dfs = [&](int pre, int cur) {
        vector<int> h;
        for (int nxt: edges[cur]) {
            if (pre == nxt) continue;
            int d = dfs(cur, nxt);
            if (d) h.push_back(d);
        }
        if (h.size() == 0) {
            return 1;
        } else if (h.size() == 1) {
            if (h[0] < k) {
                return h[0] + 1;
            } else {
                ans++;
                return 0;
            }
        } else {
            sort(h.begin(), h.end());
            if (h[0] + h[1] <= k) {
                ans += h.size() - 1;
                return 0;
            } else if (h[0] < k) {
                ans += h.size() - 1;
                return h[0] + 1;
            } else {
                ans += h.size();
                return 0;
            }
        }
    };
    if (dfs(-1, 0)) ans++;
    cout << ans << '\n';
}