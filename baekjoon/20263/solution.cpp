#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    typedef tuple<int, int, int> ti;
    typedef struct Djset {
        vector<int> p, sz;
        Djset(int n): p(n, -1), sz(n, 1) {}
        int find(int u) {
            if (p[u] < 0) return u;
            return p[u] = find(p[u]);
        }
        int size(int u) { return sz[find(u)]; }
        bool uni(int u, int v) {
            u = find(u), v = find(v);
            if (u == v) return false;
            p[u] = v;
            sz[v] += sz[u];
            return true;
        }
    } djs_t;

    int n, m;
    cin >> n >> m;
    vector<ti> es(m);
    for (auto &[b, i, j]: es) {
        cin >> i >> j >> b;
        i--, j--;
    }
    sort(es.begin(), es.end());

    int l = 0, r = m;
    while (l < r) {
        djs_t djs(n);
        int md = (l + r) / 2;
        for (int i = md; i < m; i++) {
            auto [b, u, v] = es[i];
            djs.uni(u, v);
        }
        if (count(djs.p.begin(), djs.p.end(), -1) == 1) l = md + 1;
        else r = md;
    }

    djs_t djs(n);
    vector<ti> edges;
    for (int i = r - 1; i < m; i++) {
        auto [b, u, v] = es[i];
        if (djs.uni(u, v)) edges.emplace_back(b, u, v);
    }

    ll ans = 0;
    fill(djs.p.begin(), djs.p.end(), -1);
    fill(djs.sz.begin(), djs.sz.end(), 1);
    reverse(edges.begin(), edges.end());
    for (auto [b, u, v]: edges) {
        ans += ll(b) * djs.size(u) * djs.size(v);
        djs.uni(u, v);
    }
    cout << ans << '\n';
}