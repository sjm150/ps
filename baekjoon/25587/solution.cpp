#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct Djset {
        vector<int> p, val, sz;
        Djset(vector<int> &a): p(a.size()), val(a), sz(a.size(), 1) { iota(p.begin(), p.end(), 0); }
        int find(int x) {
            if (p[x] == x) return x;
            return p[x] = find(p[x]);
        }
        void uni(int u, int v) {
            u = find(u), v = find(v);
            if (u == v) return;
            p[v] = u;
            val[u] += val[v];
            sz[u] += sz[v];
        }
        int getv(int x) { return val[find(x)]; }
        int getsz(int x) { return sz[find(x)]; }
    } djs_t;

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    for (int &a: a) {
        int b;
        cin >> b;
        a -= b;
    }

    djs_t djs(a);
    int ans = 0;
    for (int a: a) ans += a < 0;

    while (m--) {
        int c;
        cin >> c;
        if (c == 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            int xsz = djs.getsz(x), ysz = djs.getsz(y);
            if (djs.getv(x) < 0) ans -= xsz;
            if (djs.getv(y) < 0) ans -= ysz;
            djs.uni(x, y);
            if (djs.getv(x) < 0) ans += xsz + ysz;
        } else {
            cout << ans << '\n';
        }
    }
}