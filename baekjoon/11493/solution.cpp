#include <bits/stdc++.h>
using namespace std;

typedef struct Edge {
    int t, d, r, c;
    Edge(int t, int d, int r, int c): t(t), d(d), r(r), c(c) {};
} e_t;

const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int sz = n + 2;
        int s = sz - 2, e = sz - 1;
        vector<vector<e_t>> edges(sz);
        auto adde = [&](int u, int v, int d, int c) {
            edges[u].emplace_back(v, d, edges[v].size(), c);
            edges[v].emplace_back(u, -d, edges[u].size() - 1, 0);
        };
        while (m--) {
            int x, y; cin >> x >> y;
            x--, y--;
            adde(x, y, 1, inf);
            adde(y, x, 1, inf);
        }
        vector<int> vc(n), cc(n);
        for (int &c: vc) cin >> c;
        for (int &c: cc) cin >> c;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vc[i] == 0 && cc[i] == 1) {
                adde(s, i, 0, 1);
                cnt++;
            } else if (vc[i] == 1 && cc[i] == 0) {
                adde(i, e, 0, 1);
            }
        }

        int ans = 0;
        while (cnt--) {
            vector<int> pth(sz, -1), dst(sz, inf);
            vector<bool> inq(sz, false);
            queue<int> q;
            dst[s] = 0;
            inq[s] = true;
            q.push(s);

            while (!q.empty()) {
                int cur = q.front(); q.pop();
                inq[cur] = false;
                for (auto &[nxt, d, r, c]: edges[cur]) {
                    if (c > 0 && dst[nxt] > dst[cur] + d) {
                        pth[nxt] = r;
                        dst[nxt] = dst[cur] + d;
                        if (!inq[nxt]) {
                            inq[nxt] = true;
                            q.push(nxt);
                        }
                    }
                }
            }
            assert(pth[e] != -1);

            for (int cur = e; cur != s;) {
                e_t &r = edges[cur][pth[cur]];
                e_t &e = edges[r.t][r.r];
                ans += e.d;
                e.c--;
                r.c++;
                cur = r.t;
            }
        }
        cout << ans << '\n';
    }
}