#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const ll inf = 1e18;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> blk(n);
    for (int i = 0; i < n; i++) cin >> blk[i];
    blk[n - 1] = 0;
    vector<vector<pair<int, int>>> edges(n);
    while (m--) {
        int a, b, t; cin >> a >> b >> t;
        if (blk[a] || blk[b]) continue;
        edges[a].emplace_back(t, b);
        edges[b].emplace_back(t, a);
    }

    vector<ll> dst(n, inf);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dst[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (d != dst[cur]) continue;
        for (auto [t, nxt]: edges[cur]) {
            if (dst[nxt] > d + t) {
                dst[nxt] = d + t;
                pq.emplace(d + t, nxt);
            }
        }
    }

    if (dst[n - 1] < inf) cout << dst[n - 1] << '\n';
    else cout << -1 << '\n';
}