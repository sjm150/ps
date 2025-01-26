#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> l(n), r(n);
        for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
        vector<vector<int>> edges(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        ll ofs = 0;
        function<void(int, int)> dfs = [&](int pre, int cur) {
            for (int nxt: edges[cur]) {
                if (nxt == pre) continue;
                dfs(cur, nxt);
                if (l[nxt] < r[cur]) {
                    l[cur] = max(l[cur], l[nxt]);
                } else {
                    ofs += l[nxt] - r[cur];
                    l[cur] = r[cur];
                }
            }
        };
        dfs(0, 0);
        cout << l[0] + ofs << '\n';
    }
}