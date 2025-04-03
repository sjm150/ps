#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll inf = 1e18;
    typedef pair<int, int> pi;
    typedef pair<ll, int> pli;
    int n, m; cin >> n >> m;
    vector<vector<pi>> edges(n);
    while (m--) {
        int a, b, w; cin >> a >> b >> w;
        a--, b--;
        edges[a].emplace_back(w, b);
        edges[b].emplace_back(w, a);
    }
    vector<vector<ll>> dst(n, vector<ll>(2, inf));
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dst[0][0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();
        if (d > dst[cur][1]) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (dst[nxt][0] > d + w) {
                dst[nxt][1] = dst[nxt][0];
                dst[nxt][0] = d + w;
                pq.emplace(d + w, nxt);
            } else if (dst[nxt][1] > d + w) {
                dst[nxt][1] = d + w;
                pq.emplace(d + w, nxt);
            }
        }
    }
    cout << dst[n - 1][1] << '\n';
}