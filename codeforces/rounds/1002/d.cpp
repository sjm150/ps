#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    const int inf = 1e9 + 7;
    int t; cin >> t;
    while (t--) {
        int n, s1, s2; cin >> n >> s1 >> s2;
        s1--, s2--;
        vector<pi> ab, cd;
        int m1; cin >> m1;
        ab.resize(m1);
        for (auto &[a, b]: ab) {
            cin >> a >> b;
            a--, b--;
        }
        int m2; cin >> m2;
        cd.resize(m2);
        for (auto &[c, d]: cd) {
            cin >> c >> d;
            c--, d--;
        }

        int sz = n * n;
        auto vtx = [&](int x, int y) { return x * n + y; };
        vector<vector<pi>> edges(sz);
        for (auto [a, b]: ab) {
            for (auto [c, d]: cd) {
                int v = vtx(a, c), u = vtx(b, d);
                edges[v].emplace_back(abs(b - d), u);
                edges[u].emplace_back(abs(a - c), v);
                v = vtx(a, d), u = vtx(b, c);
                edges[v].emplace_back(abs(b - c), u);
                edges[u].emplace_back(abs(a - d), v);
            }
        }

        vector<int> dst(sz, inf);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        dst[vtx(s1, s2)] = 0;
        pq.emplace(0, vtx(s1, s2));
        while (!pq.empty()) {
            auto [d, cur] = pq.top(); pq.pop();
            if (d > dst[cur]) continue;
            for (auto [w, nxt]: edges[cur]) {
                if (dst[nxt] > d + w) {
                    dst[nxt] = d + w;
                    pq.emplace(d + w, nxt);
                }
            }
        }

        int ans = inf;
        for (int i = 0; i < n; i++) {
            bool ok = false;
            int v = vtx(i, i);
            for (auto [w, nxt]: edges[v]) {
                if (w == 0) {
                    ok = true;
                    break;
                }
            }
            if (ok) ans = min(ans, dst[v]);
        }
        cout << (ans < inf ? ans : -1) << '\n';
    }
}