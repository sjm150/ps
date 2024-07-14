#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e18;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    vector<vector<pair<int, int>>> edges(n);
    while (m--) {
        int u, v, b; cin >> u >> v >> b;
        u--, v--;
        edges[u].emplace_back(b, v);
        edges[v].emplace_back(b, u);
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dst(n, inf);
    dst[0] = a[0];
    pq.emplace(a[0], 0);
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (dst[v] < d) continue;
        for (auto [b, u]: edges[v]) {
            if (dst[u] > a[u] + d + b) {
                dst[u] = a[u] + d + b;
                pq.emplace(dst[u], u);
            }
        }
    }

    for (int i = 1; i < n; i++) cout << dst[i] << ' ';
    cout << '\n';
}