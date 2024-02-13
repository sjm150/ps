#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Segtree {
    int sz = 1;
    vector<ll> val;
    Segtree(int n) {
        while (sz < n) sz *= 2;
        val.resize(sz * 2, 0);
    }

    void update(int i, int k, int nd, int nl, int nr) {
        if (i < nl || nr < i) return;
        if (nl == nr) {
            val[nd] = k;
            return;
        }
        int m = (nl + nr) / 2;
        update(i, k, nd * 2, nl, m);
        update(i, k, nd * 2 + 1, m + 1, nr);
        val[nd] = val[nd * 2] + val[nd * 2 + 1];
    }
    void update(int i, int k) { update(i, k, 1, 0, sz - 1); }

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
    int n, m; cin >> n >> m;
    st_t st(n);
    while (m--) {
        int c, i, j; cin >> c >> i >> j;
        if (c == 0) cout << st.query(min(i, j) - 1, max(i, j) - 1) << '\n';
        else st.update(i - 1, j);
    }
}