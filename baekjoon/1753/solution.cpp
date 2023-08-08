#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<pair<int, int>> edges[20001];
int dst[20001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int v, e, k; cin >> v >> e >> k;
    while (e--) {
        int u, v, w; cin >> u >> v >> w;
        edges[u].emplace_back(w, v);
    }
    fill(dst, dst + v + 1, -1);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dst[k] = 0;
    pq.emplace(0, k);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dst[u]) continue;
        for (auto [w, nxt]: edges[u]) {
            if (dst[nxt] < 0 || dst[nxt] > w + d) {
                dst[nxt] = w + d;
                pq.emplace(dst[nxt], nxt);
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (dst[i] >= 0) cout << dst[i] << '\n';
        else cout << "INF\n";
    }
}