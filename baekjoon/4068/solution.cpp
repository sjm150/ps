#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int i = 1; i; i++) {
        int n, e;
        cin >> n;
        if (n == 0) break;
        cin >> e;
        
        vector<vector<int>> edges(n);
        for (int i = 0; i < e; i++) {
            int u, v; cin >> u >> v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        auto solve = [&]() {
            if (e != n - 1) return false;

            vector<bool> vst(n, false);
            function<void(int)> dfs = [&](int cur) {
                vst[cur] = true;
                for (int nxt: edges[cur]) {
                    if (!vst[nxt]) dfs(nxt);
                }
            };
            dfs(0);
            if (accumulate(vst.begin(), vst.end(), 0) < n) return false;

            vector<int> c(n, 0);
            function<void(int, int)> dfs2 = [&](int pre, int cur) {
                for (int nxt: edges[cur]) {
                    if (nxt == pre) continue;
                    dfs2(cur, nxt);
                    c[cur]++;
                }
            };
            dfs2(-1, 0);

            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (c[i] == 0) continue;
                int cnt = 0;
                for (int nxt: edges[i]) {
                    if (c[nxt]) cnt++;
                }
                if (cnt > 2) {
                    ok = false;
                    break;
                }
            }

            return ok;
        };

        cout << "Graph " << i << " is " << (solve() ? "" : "not ") << "a caterpillar.\n";
    }
}