#include <bits/stdc++.h>
using namespace std;

typedef struct Fwtree {
    vector<int> val;
    Fwtree(int n): val(n + 1, 0) {}
    void update(int x, int dv) {
        x++;
        while (x < val.size()) {
            val[x] += dv;
            x += x & -x;
        }
    }
    int query(int x) {
        x++;
        int ret = 0;
        while (x) {
            ret += val[x];
            x &= x - 1;
        }
        return ret;
    }
} fwt_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> c(n + 1);
        c[0] = 0;
        for (int i = 1; i <= n; i++) cin >> c[i];
        vector<vector<int>> edges(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int x, y; cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        vector<int> h(n + 1), p(n + 1);
        int mxh = 0;
        h[0] = 0;
        function<void(int, int)> hdfs = [&](int pre, int cur) {
            p[cur] = pre;
            h[cur] = h[pre] + 1;
            mxh = max(mxh, h[cur]);
            for (int nxt: edges[cur]) {
                if (nxt == pre) continue;
                hdfs(cur, nxt);
            }
        };
        hdfs(0, 1);

        vector<int> bidx(n + 1), l(n + 1, -1), r(n + 1, -1);
        queue<int> qu;
        int idx = 1;
        qu.push(1);
        while (!qu.empty()) {
            int cur = qu.front(); qu.pop();
            int b = bidx[cur] = idx++;
            if (l[p[cur]] < 0) l[p[cur]] = b;
            r[p[cur]] = b;
            for (int nxt: edges[cur]) {
                if (nxt == p[cur]) continue;
                qu.push(nxt);
            }
        }

        vector<bool> b(n + 1, false), ovr(n + 1, false);
        fwt_t fwt(n + 1);
        set<pair<int, int>> blks;
        int grp = 0, ocnt = 0;

        auto query = [&](int x) {
            if (l[x] > 0) return fwt.query(r[x]) - fwt.query(l[x] - 1);
            else return 0;
        };
        auto upd = [&](int x) {
            if (query(x) > 1) {
                if (!ovr[x]) {
                    ocnt++;
                    ovr[x] = true;
                }
            } else {
                if (ovr[x]) {
                    ocnt--;
                    ovr[x] = false;
                }
            }
        };
        auto run = [&](int u) {
            if (b[u]) {
                b[u] = 0;
                fwt.update(bidx[u], -1);
                blks.erase(make_pair(h[u], u));
                int bchd = query(u);
                grp += bchd + b[p[u]] - 1;
                if (bchd > 1) {
                    if (ovr[u]) {
                        ocnt--;
                        ovr[u] = false;
                    }
                }
                upd(p[u]);
            } else {
                b[u] = 1;
                fwt.update(bidx[u], 1);
                blks.emplace(h[u], u);
                int bchd = query(u);
                grp += 1 - bchd - b[p[u]];
                if (bchd > 1) {
                    if (!ovr[u]) {
                        ocnt++;
                        ovr[u] = true;
                    }
                }
                upd(p[u]);
            }
        };
        auto chk = [&]() {
            if (grp != 1) return false;
            if (ocnt == 0) return true;
            else if (ocnt == 1) return query(blks.begin()->second) == 2;
            else return false;
        };

        for (int i = 1; i <= n; i++) {
            if (c[i]) run(i);
        }
        while (q--) {
            int u; cin >> u;
            run(u);
            cout << (chk() ? "YES\n" : "NO\n");
        }
    }
}