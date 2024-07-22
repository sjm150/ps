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
        } else {
            val[nd] += lz[nd];
        }
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
    }
    void update(int l, int r, int x) { update(l, r, x, 1, 0, sz - 1); }

    int query(int i) {
        int nd = 1, nl = 0, nr = sz - 1;
        while (nl < nr) {
            prop(nd, nl, nr);
            int m = (nl + nr) / 2;
            if (i <= m) nd = nd * 2, nr = m;
            else nd = nd * 2 + 1, nl = m + 1;
        }
        prop(nd, nl, nr);
        return val[nd];
    }
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

    st_t st(n);
    while (m--) {
        int c; cin >> c;
        if (c == 1) {
            int i, w; cin >> i >> w;
            i--;
            st.update(v[i], rch[i], w);
        } else {
            int i; cin >> i;
            cout << st.query(v[i - 1]) << '\n';
        }
    }
}