#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    int m; cin >> m;
    vector<tuple<int, int, int>> op(m);
    for (auto &[l, r, c]: op) {
        cin >> l >> r >> c;
        l--, r--;
    }

    int sz = 1;
    for (int i = 1; i <= n; i++) sz *= i;
    vector<vector<pair<int, int>>> edges(sz);
    map<vector<int>, int> idx;
    queue<pair<vector<int>, int>> q;
    idx[a] = 0;
    q.emplace(a, 0);
    while (!q.empty()) {
        auto [vec, u] = q.front(); q.pop();
        for (auto &[l, r, c]: op) {
            swap(vec[l], vec[r]);
            int v = idx.size();
            auto it = idx.find(vec);
            if (it == idx.end()) {
                idx[vec] = v;
                q.emplace(vec, v);
            } else {
                v = it->second;
            }
            edges[u].emplace_back(c, v);
            swap(vec[l], vec[r]);
        }
    }

    sort(a.begin(), a.end());
    auto it = idx.find(a);
    if (it == idx.end()) {
        cout << -1 << '\n';
        return 0;
    }

    const int inf = 1e9;
    vector<int> dst(sz, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dst[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (d > dst[cur]) continue;
        for (auto &[c, nxt]: edges[cur]) {
            if (dst[nxt] > d + c) {
                dst[nxt] = d + c;
                pq.emplace(d + c, nxt);
            }
        }
    }

    if (dst[it->second] < inf) cout << dst[it->second] << '\n';
    else cout << -1 << '\n';
}