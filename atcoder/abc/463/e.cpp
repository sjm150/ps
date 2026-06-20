#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    typedef pair<ll, int> pli;
    int n, m, y;
    cin >> n >> m >> y;
    vector<vector<pli>> edges(n + 1);
    while (m--) {
        int u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        t *= 2;
        edges[u].emplace_back(t, v);
        edges[v].emplace_back(t, u);
    }
    vector<ll> x(n);
    for (ll &x: x) cin >> x;
    for (int i = 0; i < n; i++) {
        edges[i].emplace_back(2 * x[i] + y, n);
        edges[n].emplace_back(2 * x[i] + y, i);
    }

    vector<ll> dst(n + 1, 1e18);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dst[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();
        if (d > dst[cur]) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (d + w < dst[nxt]) {
                dst[nxt] = d + w;
                pq.emplace(d + w, nxt);
            }
        }
    }

    for (int i = 1; i < n; i++) cout << dst[i] / 2 << ' ';
    cout << '\n';
}