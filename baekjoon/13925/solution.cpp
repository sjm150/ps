#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

typedef struct Segtree {
    int sz = 1;
    vector<int> val, lmul, ladd;
    Segtree(int n) {
        while (sz < n) sz *= 2;
        val.resize(sz * 2, 0);
        lmul.resize(sz * 2, 1);
        ladd.resize(sz * 2, 0);
        for (int i = 0; i < n; i++) cin >> val[sz + i];
        for (int i = sz - 1; i > 0; i--) {
            val[i] = val[i * 2] + val[i * 2 + 1];
            if (val[i] >= mod) val[i] -= mod;
        }
    }

    void prop(int nd, int nl, int nr) {
        if (lmul[nd] != 1 || ladd[nd] != 0) {
            if (nd < sz) {
                lmul[nd * 2] = ll(lmul[nd * 2]) * lmul[nd] % mod;
                ladd[nd * 2] = (ll(ladd[nd * 2]) * lmul[nd] + ladd[nd]) % mod;
                lmul[nd * 2 + 1] = ll(lmul[nd * 2 + 1]) * lmul[nd] % mod;
                ladd[nd * 2 + 1] = (ll(ladd[nd * 2 + 1]) * lmul[nd] + ladd[nd]) % mod;
            }
            val[nd] = (ll(val[nd]) * lmul[nd] + ll(nr - nl + 1) * ladd[nd]) % mod;
            lmul[nd] = 1;
            ladd[nd] = 0;
        }
    }

    void update(int l, int r, int mul, int add, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return;
        if (l <= nl && nr <= r) {
            lmul[nd] = ll(lmul[nd]) * mul % mod;
            ladd[nd] = (ll(ladd[nd]) * mul + add) % mod;
            prop(nd, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        update(l, r, mul, add, nd * 2, nl, m);
        update(l, r, mul, add, nd * 2 + 1, m + 1, nr);
        val[nd] = (val[nd * 2] + val[nd * 2 + 1]) % mod;
    }
    void update(int l, int r, int mul, int add) { update(l, r, mul, add, 1, 0, sz - 1); }

    int query(int l, int r, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return val[nd];
        int m = (nl + nr) / 2;
        return (query(l, r, nd * 2, nl, m) + query(l, r, nd * 2 + 1, m + 1, nr)) % mod;
    }
    int query(int l, int r) { return query(l, r, 1, 0, sz - 1); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    st_t st(n);
    int m; cin >> m;
    while (m--) {
        int c, x, y; cin >> c >> x >> y;
        x--, y--;
        if (c == 4) {
            cout << st.query(x, y) << '\n';
        } else {
            int v; cin >> v;
            if (c == 1) st.update(x, y, 1, v);
            else if (c == 2) st.update(x, y, v, 0);
            else st.update(x, y, 0, v);
        }
    }
}