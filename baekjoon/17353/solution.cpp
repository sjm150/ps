#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef struct Segtree {
    int sz = 1;
    vector<ll> val, lzc, lzv;
    Segtree(vector<int> &a) {
        while (sz < a.size()) sz *= 2;
        val = lzc = lzv = vector<ll>(sz * 2, 0);
        for (int i = 0; i < a.size(); i++) val[sz + i] = a[i];
    }

    void prop(int nd, int nl, int nr) {
        if (lzc[nd]) {
            if (nd < sz) {
                lzc[nd * 2] += lzc[nd];
                lzv[nd * 2] += lzv[nd];
                lzc[nd * 2 + 1] += lzc[nd];
                lzv[nd * 2 + 1] += lzv[nd];
            } else {
                val[nd] += (nl + 1) * lzc[nd] - lzv[nd];
            }
            lzc[nd] = lzv[nd] = 0;
        }
    }

    void update(int l, int r, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return;
        if (l <= nl && nr <= r) {
            lzc[nd]++;
            lzv[nd] += l;
            prop(nd, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        update(l, r, nd * 2, nl, m);
        update(l, r, nd * 2 + 1, m + 1, nr);
    }
    void update(int l, int r) { update(l, r, 1, 0, sz - 1); }

    ll query(int i) {
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
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    st_t st(a);
    int q; cin >> q;
    while (q--) {
        int c; cin >> c;
        if (c == 1) {
            int l, r; cin >> l >> r;
            st.update(l - 1, r - 1);
        } else {
            int x; cin >> x;
            cout << st.query(x - 1) << '\n';
        }
    }
}