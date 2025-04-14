#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct Edge {
        int t, w, r, c;
        Edge(int t, int w, int r, int c): t(t), w(w), r(r), c(c) {}
    } e_t;
    const int inf = 1e9;
    int v;
    while (cin >> v) {
        int e; cin >> e;
        int sz = v * 2;
        int st = 1, en = sz - 2;
        vector<vector<e_t>> edges(sz);
        auto adde = [&](int u, int v, int w) {
            edges[u].emplace_back(v, w, edges[v].size(), 1);
            edges[v].emplace_back(u, -w, edges[u].size() - 1, 0);
        };
        for (int i = 0; i < v; i++) adde(i * 2, i * 2 + 1, 0);
        while (e--) {
            int a, b, c; cin >> a >> b >> c;
            a--, b--;
            adde(a * 2 + 1, b * 2, c);
        }

        int cst = 0;
        for (int i = 0; i < 2; i++) {
            vector<int> pth(sz, -1), dst(sz, inf);
            vector<bool> inq(sz, false);
            queue<int> q;
            dst[st] = 0;
            inq[st] = true;
            q.push(st);

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
            if (pth[en] < 0) break;

            for (int cur = en; cur != st;) {
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
}