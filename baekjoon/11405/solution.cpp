#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct Edge {
        int t, w, r, c;
        Edge(int t, int w, int r, int c): t(t), w(w), r(r), c(c) {}
    } e_t;
    const int inf = 1e9;
    int n, m; cin >> n >> m;
    int sz = n + m + 2;
    int s = sz - 2, e = sz - 1;
    vector<vector<e_t>> edges(sz);
    auto adde = [&](int u, int v, int w, int c) {
        edges[u].emplace_back(v, w, edges[v].size(), c);
        edges[v].emplace_back(u, -w, edges[u].size() - 1, 0);
    };
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        adde(s, i, 0, a);
    }
    for (int i = 0; i < m; i++) {
        int b; cin >> b;
        adde(i + n, e, 0, b);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int c; cin >> c;
            adde(j, i + n, c, inf);
        }
    }

    int cst = 0;
    for (;;) {
        vector<int> pth(sz, -1), dst(sz, inf);
        vector<bool> inq(sz, false);
        queue<int> q;
        dst[s] = 0;
        inq[s] = true;
        q.push(s);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            inq[cur] = false;
            for (auto &[nxt, w, r, c] : edges[cur]) {
                if (c > 0 && dst[nxt] > dst[cur] + w) {
                    pth[nxt] = r;
                    dst[nxt] = dst[cur] + w;
                    if (!inq[nxt]) {
                        inq[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
        if (pth[e] < 0) break;

        for (int cur = e; cur != s;) {
            auto &r = edges[cur][pth[cur]];
            auto &e = edges[r.t][r.r];
            cst += e.w;
            e.c--;
            r.c++;
            cur = r.t;
        }
    }

    cout << cst << '\n';
}