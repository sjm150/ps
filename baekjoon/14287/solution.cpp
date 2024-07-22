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

    void update(int i, int x, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (i < nl || nr < i) return;
        if (nl == nr) {
            lz[nd] += x;
            prop(nd, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        update(i, x, nd * 2, nl, m);
        update(i, x, nd * 2 + 1, m + 1, nr);
        val[nd] = val[nd * 2] + val[nd * 2 + 1];
    }
    void update(int i, int x) { update(i, x, 1, 0, sz - 1); }

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

    st_t st(n);
    while (m--) {
        int c; cin >> c;
        if (c == 1) {
            int i, w; cin >> i >> w;
            st.update(v[i - 1], w);
        } else {
            int i; cin >> i;
            i--;
            cout << st.query(v[i], rch[i]) << '\n';
        }
    }
}