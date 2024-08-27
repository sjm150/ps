#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int p, t; cin >> p >> t;
    vector<vector<pi>> edges(p);
    while (t--) {
        int u, v, l; cin >> u >> v >> l;
        edges[u].emplace_back(l, v);
        edges[v].emplace_back(l, u);
    }

    vector<int> dst(p, inf);
    vector<vector<pi>> pre(p);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dst[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (dst[cur] != d) continue;
        for (auto &[l, nxt]: edges[cur]) {
            if (dst[nxt] > d + l) {
                dst[nxt] = d + l;
                pre[nxt] = vector<pi>(1, {l, cur});
                pq.emplace(dst[nxt], nxt);
            } else if (dst[nxt] == d + l) {
                pre[nxt].emplace_back(l, cur);
            }
        }
    }

    long long ans = 0;
    vector<bool> vst(p, false);
    queue<int> q;
    vst[p - 1] = true;
    q.push(p - 1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto &[l, nxt]: pre[cur]) {
            ans += l;
            if (vst[nxt]) continue;
            vst[nxt] = true;
            q.push(nxt);
        }
    }

    cout << ans * 2 << '\n';
}