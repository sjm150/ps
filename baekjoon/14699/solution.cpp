#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> h(n);
    for (int &h: h) cin >> h;

    vector<vector<int>> edges(n);
    while (m--) {
        int u, v; cin >> u >> v;
        u--, v--;
        if (h[u] > h[v]) edges[v].push_back(u);
        else edges[u].push_back(v);
    }

    vector<pair<int, int>> ord(n);
    for (int i = 0; i < n; i++) ord[i] = {h[i], i};
    sort(ord.begin(), ord.end(), greater<pair<int, int>>());

    vector<int> cnt(n);
    for (auto &[_h, v]: ord) {
        cnt[v] = 1;
        for (int nxt: edges[v]) cnt[v] = max(cnt[v], cnt[nxt] + 1);
    }

    for (int c: cnt) cout << c << '\n';
}