#include <bits/stdc++.h>
using namespace std;

typedef struct Segtree {
    int sz = 1;
    vector<int> val, lz;
    Segtree(int n) {
        while (sz < n) sz <<= 1;
        val = lz = vector<int>(2 * sz, 0);
        for (int i = 0; i < n; i++) cin >> val[sz + i];
        for (int i = sz - 1; i > 0; i--) val[i] = val[2 * i] ^ val[2 * i + 1];
    }

    void prop(int nd, int nl, int nr) {
        if (lz[nd]) {
            if (nd < sz) {
                lz[nd * 2] ^= lz[nd];
                lz[nd * 2 + 1] ^= lz[nd];
            } else {
                val[nd] ^= lz[nd];
            }
            lz[nd] = 0;
        }
    }

    void update(int l, int r, int x, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr <= l || r <= nl) return;
        if (l <= nl && nr <= r) {
            lz[nd] ^= x;
            prop(nd, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        update(l, r, x, nd * 2, nl, m);
        update(l, r, x, nd * 2 + 1, m, nr);
        val[nd] = val[nd * 2] ^ val[nd * 2 + 1];
    }
    void update(int l, int r, int x) { update(l, r, x, 1, 0, sz); }

    int query(int l, int r, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr <= l || r <= nl) return 0;
        if (l <= nl && nr <= r) return val[nd];
        int m = (nl + nr) / 2;
        return query(l, r, nd * 2, nl, m) ^ query(l, r, nd * 2 + 1, m, nr);
    }
    int query(int l, int r) { return query(l, r, 1, 0, sz); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    st_t st(n);
    int m; cin >> m;
    while (m--) {
        int c, i, j; cin >> c >> i >> j;
        if (c == 1) {
            int k; cin >> k;
            st.update(i, j + 1, k);
        } else {
            cout << st.query(i, j + 1) << '\n';
        }
    }
}