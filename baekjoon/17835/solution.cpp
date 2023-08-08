#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
const ll inf = 123456789876;

vector<pi> edges[100001];
ll dst[100001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    while (m--) {
        int u, v, c; cin >> u >> v >> c;
        edges[v].emplace_back(c, u);
    }
    fill(dst, dst + n + 1, inf);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    while (k--) {
        int v; cin >> v;
        dst[v] = 0;
        pq.emplace(0, v);
    }
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
    int maxi = 0;
    ll maxd = 0;
    for (int i = 1; i <= n; i++) {
        if (dst[i] < inf && maxd < dst[i]) {
            maxi = i;
            maxd = dst[i];
        }
    }
    cout << maxi << '\n' << maxd << '\n';
}