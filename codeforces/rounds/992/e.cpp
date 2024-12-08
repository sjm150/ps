#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<vector<int>> edges(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        vector<vector<int>> cst(n);
        function<void(int, int, int)> dfs = [&](int pp, int p, int cur) {
            if (pp < 0) {
                if (p == 0) cst[cur].push_back(1);
            } else {
                cst[cur] = cst[pp];
                cst[cur].push_back(2 * edges[p].size());
                sort(cst[cur].begin(), cst[cur].end(), greater<int>());
            }
            for (int nxt: edges[cur]) {
                if (p == nxt) continue;
                dfs(p, cur, nxt);
            }
        };
        dfs(-1, -1, 0);

        while (q--) {
            int v, p; cin >> v >> p;
            v--;
            int sum = 0;
            for (int c: cst[v]) {
                if (p) {
                    sum += min(2, c);
                    p--;
                } else {
                    sum += c;
                }
            }
            cout << sum << '\n';
        }
    }
}