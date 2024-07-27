#include <bits/stdc++.h>
using namespace std;

typedef struct Edge {
    int t, c, f, r;
    Edge(int t, int c, int r): t(t), c(c), f(0), r(r) {}
} e_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    int sz = n + m + 3;
    const int s = sz - 3, ss = sz - 2, e = sz - 1;
    vector<vector<e_t>> edges(sz);
    auto add = [&](int u, int v, int c) {
        edges[u].emplace_back(v, c, edges[v].size());
        edges[v].emplace_back(u, 0, edges[u].size() - 1);
    };
    add(s, ss, k);
    for (int i = 0; i < n; i++) {
        add(s, i, 1);
        add(ss, i, k);
    }
    for (int i = n; i < n + m; i++) add(i, e, 1);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        while (c--) {
            int w; cin >> w;
            add(i, n + w - 1, 1);
        }
    }

    int ans = 0;
    for (;;) {
        vector<int> pre(sz, -1), pth(sz, -1);
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int i = 0; i < edges[cur].size(); i++) {
                auto &[nxt, c, f, r] = edges[cur][i];
                if (pre[nxt] < 0 && c - f > 0) {
                    pre[nxt] = cur;
                    pth[nxt] = i;
                    q.push(nxt);
                }
            }
        }
        if (pre[e] < 0) break;

        int mn = 1e9;
        for (int i = e; i != s; i = pre[i]) {
            auto &e = edges[pre[i]][pth[i]];
            mn = min(mn, e.c - e.f);
        }
        for (int i = e; i != s; i = pre[i]) {
            auto &e = edges[pre[i]][pth[i]];
            e.f += mn;
            edges[i][e.r].f -= mn;
        }
        ans += mn;
    }

    cout << ans << '\n';
}