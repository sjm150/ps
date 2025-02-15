#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int inf = 1e9;
    typedef pair<int, int> pi;
    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, p, m; cin >> n >> p >> m;
        vector<pi> xv(p);
        for (auto &[x, v]: xv) {
            cin >> x >> v;
            x--;
        }
        vector<vector<pi>> edges(n);
        while (m--) {
            int d, l; cin >> d >> l;
            int p = -1;
            while (l--) {
                int c; cin >> c;
                c--;
                if (p >= 0) {
                    edges[p].emplace_back(d, c);
                    edges[c].emplace_back(d, p);
                }
                p = c;
            }
        }

        vector<int> mx(n, 0);
        vector<bool> ok(n, true);
        for (auto [x, v]: xv) {
            vector<int> dst(n, inf);
            priority_queue<pi, vector<pi>, greater<pi>> pq;
            dst[x] = 0;
            pq.emplace(0, x);
            while (!pq.empty()) {
                auto [d, cur] = pq.top(); pq.pop();
                if (dst[cur] < d) continue;
                for (auto &[w, nxt]: edges[cur]) {
                    if (dst[nxt] > d + w) {
                        dst[nxt] = d + w;
                        pq.emplace(d + w, nxt);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (dst[i] < inf) mx[i] = max(mx[i], dst[i] * v);
                else ok[i] = false;
            }
        }

        int ans = inf;
        for (int i = 0; i < n; i++) {
            if (ok[i]) ans = min(ans, mx[i]);
        }
        cout << "Case #" << tc << ": ";
        cout << (ans < inf ? ans : -1) << '\n';
    }
}