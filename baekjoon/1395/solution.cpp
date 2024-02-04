#include <bits/stdc++.h>
using namespace std;

typedef struct Segtree {
    int sz = 1;
    vector<int> val;
    vector<bool> lz;
    Segtree(int n) {
        while (sz < n) sz *= 2;
        val.resize(sz * 2, 0);
        lz.resize(sz * 2, false);
    }

    void prop(int nd, int nl, int nr) {
        if (lz[nd]) {
            if (nd < sz) {
                lz[nd * 2] = !lz[nd * 2];
                lz[nd * 2 + 1] = !lz[nd * 2 + 1];
            }
            val[nd] = nr - nl + 1 - val[nd];
            lz[nd] = false;
        }
    }

    void update(int nd, int nl, int nr, int l, int r) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return;
        if (l <= nl && nr <= r) {
            lz[nd] = !lz[nd];
            prop(nd, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        update(nd * 2, nl, m, l, r);
        update(nd * 2 + 1, m + 1, nr, l, r);
        val[nd] = val[nd * 2] + val[nd * 2 + 1];
    }
    void update(int l, int r) { update(1, 0, sz - 1, l, r); }

    int query(int nd, int nl, int nr, int l, int r) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return val[nd];
        int m = (nl + nr) / 2;
        return query(nd * 2, nl, m, l, r) + query(nd * 2 + 1, m + 1, nr, l, r);
    }
    int query(int l, int r) { return query(1, 0, sz - 1, l, r); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    st_t st(n);
    while (m--) {
        int o, s, t; cin >> o >> s >> t;
        if (o == 0) st.update(s - 1, t - 1);
        else cout << st.query(s - 1, t - 1) << '\n';
    }
}