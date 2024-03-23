#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<vector<int>> edges(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int v, u; cin >> v >> u;
            edges[v].emplace_back(u);
            edges[u].emplace_back(v);
        }

        int cnt, x;
        vector<int> sz(n + 1);
        function<void(int, int)> dfs = [&](int pre, int cur) {
            sz[cur] = 1;
            for (int nxt: edges[cur]) {
                if (pre == nxt) continue;
                dfs(cur, nxt);
                if (sz[nxt] >= x) cnt++;
                else sz[cur] += sz[nxt];
            }
        };

        int l = 1, r = n;
        while (l < r) {
            cnt = 0;
            x = (l + r) / 2;
            dfs(0, 1);
            if (sz[1] >= x) cnt++;
            if (cnt - 1 >= k) l = x + 1;
            else r = x;
        }

        cout << r - 1 << '\n';
    }
}