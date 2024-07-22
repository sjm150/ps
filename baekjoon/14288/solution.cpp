#include <bits/stdc++.h>
using namespace std;

typedef struct Segtree {
    int sz = 1;
    vector<int> val, lz;
    Segtree(int n) {
        while (sz < n) sz *= 2;
        val = lz = vector<int>(sz * 2, 0);
    }

    void prop(int nd, int nl, int nr) {
        if (!lz[nd]) return;
        if (nd < sz) {
            lz[nd * 2] += lz[nd];
            lz[nd * 2 + 1] += lz[nd];
        }
        val[nd] += lz[nd] * (nr - nl + 1);
        lz[nd] = 0;
    }

    void update(int l, int r, int x, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return;
        if (l <= nl && nr <= r) {
            lz[nd] += x;
            prop(nd, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        update(l, r, x, nd * 2, nl, m);
        update(l, r, x, nd * 2 + 1, m + 1, nr);
        val[nd] = val[nd * 2] + val[nd * 2 + 1];
    }
    void update(int l, int r, int x) { update(l, r, x, 1, 0, sz - 1); }

    int query(int l, int r, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return val[nd];
        int m = (nl + nr) / 2;
        return query(l, r, nd * 2, nl, m) + query(l, r, nd * 2 + 1, m + 1, nr);
    }
    int query(int l, int r) { return query(l, r, 1, 0, sz - 1); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (p > 0) edges[p - 1].push_back(i);
    }

    vector<int> v(n), rch(n);
    int vidx = 0;
    function<void(int)> dfs = [&](int cur) {
        v[cur] = rch[cur] = vidx++;
        for (int nxt: edges[cur]) {
            dfs(nxt);
            rch[cur] = max(rch[cur], rch[nxt]);
        }
    };
    dfs(0);

    st_t st0(n), st1(n);
    int sel = 0;
    while (m--) {
        int c; cin >> c;
        if (c == 1) {
            int i, w; cin >> i >> w;
            i--;
            if (sel == 0) st0.update(v[i], rch[i], w);
            else st1.update(v[i], v[i], w);
        } else if (c == 2) {
            int i; cin >> i;
            i--;
            cout << st0.query(v[i], v[i]) + st1.query(v[i], rch[i]) << '\n';
        } else {
            sel = 1 - sel;
        }
    }
}