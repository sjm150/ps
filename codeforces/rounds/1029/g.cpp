#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<pi>> edges(n);
        int mn = 1e9, mx = 0;
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            edges[u].emplace_back(w, v);
            edges[v].emplace_back(w, u);
            mn = min(mn, w);
            mx = max(mx, w);
        }

        vector<int> r(n, 0);
        auto mst = [&](int s) {
            vector<bool> vst(n, false);
            priority_queue<pi, vector<pi>, greater<pi>> pq;
            int mx = 0;
            pq.emplace(0, s);
            while (!pq.empty()) {
                auto [w, cur] = pq.top();
                pq.pop();
                if (vst[cur]) continue;
                vst[cur] = true;
                mx = max(mx, w);
                r[cur] = max(r[cur], mx);
                for (auto [w, nxt]: edges[cur]) {
                    if (!vst[nxt]) pq.emplace(w, nxt);
                }
            }
        };
        mst(0);
        mst(n - 1);

        int ans = 2e9 + 1;
        for (int u = 0; u < n; u++) {
            for (auto [w, v]: edges[u]) ans = min(ans, w + min(r[u], r[v]));
        }
        cout << ans << '\n';
    }
}