#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Segtree {
    int sz = 1;
    vector<ll> val;
    Segtree(int n) {
        while (sz < n) sz *= 2;
        val.resize(sz * 2, 0);
        for (int i = 0; i < n; i++) cin >> val[sz + i];
        for (int i = sz - 1; i > 0; i--) val[i] = val[i * 2] + val[i * 2 + 1];
    }

    void update(int x, int v, int nd, int nl, int nr) {
        if (x < nl || nr < x) return;
        if (nl == nr) {
            val[nd] = v;
            return;
        }
        int m = (nl + nr) / 2;
        update(x, v, nd * 2, nl, m);
        update(x, v, nd * 2 + 1, m + 1, nr);
        val[nd] = val[nd * 2] + val[nd * 2 + 1];
    }
    void update(int x, int v) { update(x, v, 1, 0, sz - 1); }

    ll query(int l, int r, int nd, int nl, int nr) {
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return val[nd];
        int m = (nl + nr) / 2;
        return query(l, r, nd * 2, nl, m) + query(l, r, nd * 2 + 1, m + 1, nr);
    }
    ll query(int l, int r) { return query(l, r, 1, 0, sz - 1); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    st_t st(n);
    while (q--) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        cout << st.query(min(x, y) - 1, max(x, y) - 1) << '\n';
        st.update(a - 1, b);
    }
}