#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
const ll inf = 1e15;

vector<pi> edges[100001];
ll dst[100001];
void dijk(int v, ll lim, int n) {
    fill(dst, dst + n + 1, inf);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dst[v] = 0;
    pq.emplace(0, v);
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (d != dst[cur]) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (w <= lim && dst[nxt] > d + w) {
                dst[nxt] = d + w;
                pq.emplace(dst[nxt], nxt);
            }
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, a, b; cin >> n >> m >> a >> b;
    ll c; cin >> c;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        edges[u].emplace_back(w, v);
        edges[v].emplace_back(w, u);
    }
    ll s = 1, e = c + 1;
    while (s < e) {
        ll lim = (s + e) / 2;
        dijk(a, lim, n);
        if (dst[b] <= c) e = lim;
        else s = lim + 1;
    }
    if (s <= c) cout << s << '\n';
    else cout << -1 << '\n';
}