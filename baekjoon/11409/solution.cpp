#include <bits/stdc++.h>
using namespace std;

typedef struct Edge {
    int t, d, r, c, f;
    Edge(int t, int d, int r, int c): t(t), d(d), r(r), c(c), f(0) {}
} e_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int sz = n + m + 2;
    int s = sz - 2, e = sz - 1;
    vector<vector<e_t>> edges(sz);
    auto adde = [&](int u, int v, int d) {
        edges[u].emplace_back(v, d, edges[v].size(), 1);
        edges[v].emplace_back(u, -d, edges[u].size() - 1, 0);
    };
    for (int i = 0; i < n; i++) adde(s, i, 0);
    for (int i = 0; i < m; i++) adde(i + n, e, 0);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        while (c--) {
            int w, p; cin >> w >> p;
            adde(i, w + n - 1, -p);
        }
    }

    int cnt = 0, cst = 0;
    for (;;) {
        vector<int> pth(sz, -1), dst(sz, 1e9);
        vector<bool> inq(sz, false);
        queue<int> q;
        dst[s] = 0;
        inq[s] = true;
        q.push(s);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            inq[cur] = false;
            for (auto &[nxt, d, r, c, f]: edges[cur]) {
                if (c - f > 0 && dst[nxt] > dst[cur] + d) {
                    pth[nxt] = r;
                    dst[nxt] = dst[cur] + d;
                    if (!inq[nxt]) {
                        inq[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
        if (pth[e] == -1) break;

        for (int cur = e; cur != s;) {
            auto &r = edges[cur][pth[cur]];
            auto &e = edges[r.t][r.r];
            cst -= e.d;
            e.f++;
            r.f--;
            cur = r.t;
        }
        cnt++;
    }

    cout << cnt << '\n';
    cout << cst << '\n';
}