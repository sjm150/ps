#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> edges(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        vector<int> hcnt(n + 1, 0), mcnt(n, 0);
        function<int(int, int, int)> dfs = [&](int pre, int cur, int h) {
            int mxh = h;
            hcnt[h]++;
            for (int nxt: edges[cur]) {
                if (nxt == pre) continue;
                mxh = max(mxh, dfs(cur, nxt, h + 1));
            }
            mcnt[mxh]++;
            return mxh;
        };
        dfs(0, 1, 0);
        for (int i = n - 1; i; i--) hcnt[i - 1] += hcnt[i];
        for (int i = 1; i < n; i++) mcnt[i] += mcnt[i - 1];
        int ans = n - 1;
        for (int h = 1; h < n; h++) ans = min(ans, hcnt[h + 1] + mcnt[h - 1]);
        cout << ans << '\n';
    }
}