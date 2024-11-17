#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct Edge {
        int t, r, c;
        Edge(int t, int r, int c): t(t), r(r), c(c) {}
    } e_t;
    int n, m, k; cin >> n >> m >> k;
    int s = 0, s0 = n + m + 1, s1 = s0 + 1, e = s1 + 1, sz = e + 1;
    vector<vector<e_t>> edges(sz);
    auto adde = [&](int u, int v, int c) {
        edges[u].emplace_back(v, edges[v].size(), c);
        edges[v].emplace_back(u, edges[u].size() - 1, 0);
    };
    adde(s, s0, n);
    adde(s, s1, k);
    for (int i = 1; i <= n; i++) {
        adde(s0, i, 1);
        adde(s1, i, 1);
        int c; cin >> c;
        while (c--) {
            int j; cin >> j;
            adde(i, n + j, 1);
        }
    }
    for (int i = 1; i <= m; i++) adde(n + i, e, 1);

    int ans = 0;
    for (;;) {
        vector<int> pth(sz, -1);
        queue<int> q;
        pth[s] = sz;
        q.push(s);
        while (!q.empty() && pth[e] < 0) {
            int cur = q.front(); q.pop();
            for (auto &[nxt, r, c]: edges[cur]) {
                if (pth[nxt] < 0 && c > 0) {
                    pth[nxt] = r;
                    q.push(nxt);
                }
            }
        }
        if (pth[e] < 0) break;

        for (int cur = e; cur != s;) {
            e_t &r = edges[cur][pth[cur]];
            e_t &e = edges[r.t][r.r];
            e.c--;
            r.c++;
            cur = r.t;
        }
        ans++;
    }

    cout << ans << '\n';
}