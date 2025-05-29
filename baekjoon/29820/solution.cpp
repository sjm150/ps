#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    typedef pair<int, int> pi;
    vector<vector<pi>> edges(n);
    while (k--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].emplace_back(0, v);
        edges[v].emplace_back(0, u);
    }
    
    vector<pair<int, int>> ord(n);
    for (int i = 0; i < n; i++) ord[i] = {a[i], i};
    sort(ord.begin(), ord.end());
    for (int i = 0; i < n - 1; i++) {
        int u = ord[i].second, v = ord[i + 1].second, w = abs(ord[i].first - ord[i + 1].first);
        edges[u].emplace_back(w, v);
        edges[v].emplace_back(w, u);
    }

    vector<int> dst(n, 1e9);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dst[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();
        if (d > dst[cur]) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (dst[nxt] > d + w) {
                dst[nxt] = d + w;
                pq.emplace(d + w, nxt);
            }
        }
    }

    for (int d: dst) cout << d << ' ';
    cout << '\n';
}