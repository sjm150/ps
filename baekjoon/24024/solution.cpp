#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll inf = 1e18;
    typedef pair<ll, int> pli;
    typedef struct Edge {
        int t, w, p;
        Edge(int t, int w, int p): t(t), w(w), p(p) {}
    } e_t;
    int n, m, x; cin >> n >> m >> x;
    vector<vector<e_t>> edges(n);
    while (m--) {
        int u, v, w, p; cin >> u >> v >> w >> p;
        u--, v--;
        edges[u].emplace_back(v, w, p);
        edges[v].emplace_back(u, w, p);
    }

    vector<ll> dst(n);
    auto dijk = [&](int v) {
        int a[] = {0, v, x - v};
        fill(dst.begin(), dst.end(), inf);
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        dst[0] = 0;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [d, cur] = pq.top(); pq.pop();
            if (dst[cur] < d) continue;
            if (cur == n - 1) break;
            for (auto &[nxt, w, p]: edges[cur]) {
                if (dst[nxt] > d + w + a[p]) {
                    dst[nxt] = d + w + a[p];
                    pq.emplace(dst[nxt], nxt);
                }
            }
        }
        return dst[n - 1];
    };

    ll l = 0, r = x;
    while (r - l >= 3) {
        int ll = (l * 2 + r) / 3, rr = (l + r * 2) / 3;
        if (dijk(ll) < dijk(rr)) l = ll;
        else r = rr;
    }

    ll ans = 0;
    for (int i = l; i <= r; i++) ans = max(ans, dijk(i));
    cout << ans << '\n';
}