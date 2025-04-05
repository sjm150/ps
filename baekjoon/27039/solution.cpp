#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    const int inf = 1e9 + 1e8;
    int n, p, c; cin >> n >> p >> c;
    vector<int> pos(n);
    for (int &p: pos) {
        cin >> p;
        p--;
    }
    vector<vector<pi>> edges(p);
    while (c--) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        edges[u].emplace_back(w, v);
        edges[v].emplace_back(w, u);
    }

    vector<vector<int>> dst(n, vector<int>(p, inf));
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (int i = 0; i < n; i++) {
        dst[i][pos[i]] = 0;
        pq.emplace(0, pos[i]);
        while (!pq.empty()) {
            auto [d, cur] = pq.top();
            pq.pop();
            if (d > dst[i][cur]) continue;
            for (auto [w, nxt]: edges[cur]) {
                if (dst[i][nxt] > d + w) {
                    dst[i][nxt] = d + w;
                    pq.emplace(d + w, nxt);
                }
            }
        }
    }

    int ans = inf;
    for (int i = 0; i < p; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) cur += dst[j][i];
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}