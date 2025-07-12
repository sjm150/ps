#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    const int inf = 1e9;
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> edges(n);
    while (m--) {
        int a, b, l;
        cin >> a >> b >> l;
        a--, b--;
        edges[a].emplace_back(l, b);
        edges[b].emplace_back(l, a);
    }

    vector<int> dst(n);
    vector<pi> pre(n);
    auto dijk = [&](bool trk) {
        fill(dst.begin(), dst.end(), inf);
        if (trk) fill(pre.begin(), pre.end(), make_pair(-1, -1));
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        dst[0] = 0;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [d, cur] = pq.top();
            pq.pop();
            if (d > dst[cur]) continue;
            for (int i = 0; i < int(edges[cur].size()); i++) {
                auto [w, nxt] = edges[cur][i];
                if (dst[nxt] > d + w) {
                    dst[nxt] = d + w;
                    if (trk) pre[nxt] = make_pair(cur, i);
                    pq.emplace(d + w, nxt);
                }
            }
        }
    };

    dijk(true);
    int ans = dst[n - 1], bss = dst[n - 1];
    for (int cur = n - 1; cur; cur = pre[cur].first) {
        edges[pre[cur].first][pre[cur].second].first *= 2;
        dijk(false);
        ans = max(ans, dst[n - 1]);
        edges[pre[cur].first][pre[cur].second].first /= 2;
    }
    cout << ans - bss << '\n';
}