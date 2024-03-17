#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int inf = 2 * 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int v, e; cin >> v >> e;
    vector<vector<pi>> edges(v + 1);
    while (e--) {
        int u, v, w; cin >> u >> v >> w;
        edges[u].emplace_back(w, v);
        edges[v].emplace_back(w, u);
    }

    vector<int> dst(v + 1);
    auto dijk = [&](int s) {
        fill(dst.begin(), dst.end(), inf);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        dst[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, cur] = pq.top(); pq.pop();
            if (d != dst[cur]) continue;
            for (auto [w, nxt]: edges[cur]) {
                if (dst[nxt] > w + d) {
                    dst[nxt] = w + d;
                    pq.emplace(w + d, nxt);
                }
            }
        }
    };

    vector<int> p(10);
    for (int i = 0; i < 10; i++) cin >> p[i];
    vector<long long> ldst(10, -1);
    int pre = 0;
    ldst[0] = 0;
    for (int i = 1; i < 10; i++) {
        dijk(p[pre]);
        while (i < 10 && dst[p[i]] == inf) i++;
        if (i < 10) {
            ldst[i] = ldst[pre] + dst[p[i]];
            pre = i;
        }
    }

    int s; cin >> s;
    dijk(s);
    int ans = inf;
    for (int i = 0; i < 10; i++) {
        if (dst[p[i]] <= ldst[i]) ans = min(ans, p[i]);
    }
    if (ans < inf) cout << ans << '\n';
    else cout << -1 << '\n';
}