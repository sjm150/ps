#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n, m, k, s, t; cin >> n >> m >> k >> s >> t;
    vector<vector<pair<int, int>>> edges(n);
    while (m--) {
        int a, b, t; cin >> a >> b >> t;
        edges[a - 1].emplace_back(b - 1, t);
    }
    vector<ll> dst(n, -1);
    dst[s - 1] = 0;
    while (k--) {
        for (int i = 0; i < n; i++) {
            if (dst[i] < 0) continue;
            for (auto [nxt, d]: edges[i]) dst[nxt] = max(dst[nxt], dst[i] + d);
        }
        for (int i = 0; i < n; i++) {
            for (auto [nxt, d]: edges[i]) dst[i] = max(dst[i], dst[nxt]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (dst[i] < 0) continue;
        for (auto [nxt, d]: edges[i]) dst[nxt] = max(dst[nxt], dst[i] + d);
    }
    cout << dst[t - 1] << '\n';
}