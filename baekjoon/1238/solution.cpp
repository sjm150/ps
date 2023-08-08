#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int inf = 123456789;

vector<pi> edges[1001], redges[1001];
int dst[1001], rdst[1001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, x; cin >> n >> m >> x;
    while (m--) {
        int u, v, t; cin >> u >> v >> t;
        edges[u].emplace_back(t, v);
        redges[v].emplace_back(t, u);
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    fill(dst, dst + n + 1, inf);
    dst[x] = 0;
    pq.emplace(0, x);
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (d != dst[cur]) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (dst[nxt] > d + w) {
                dst[nxt] = d + w;
                pq.emplace(dst[nxt], nxt);
            }
        }
    }
    fill(rdst, rdst + n + 1, inf);
    rdst[x] = 0;
    pq.emplace(0, x);
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (d != rdst[cur]) continue;
        for (auto [w, nxt]: redges[cur]) {
            if (rdst[nxt] > d + w) {
                rdst[nxt] = d + w;
                pq.emplace(rdst[nxt], nxt);
            }
        }
    }
    int maxt = 0;
    for (int i = 1; i <= n; i++) {
        if (maxt < dst[i] + rdst[i]) maxt = dst[i] + rdst[i];
    }
    cout << maxt << '\n';
}