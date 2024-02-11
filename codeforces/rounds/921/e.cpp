#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

typedef struct Segtree {
    int sz = 1;
    vector<ll> val;
    vector<int> lzx, lzv;
    Segtree(int n, vector<pi>& in) {
        while (sz < n) sz *= 2;
        val.resize(sz * 2, 0);
        lzx.resize(sz * 2, -1);
        lzv.resize(sz * 2);
        int idx = 0;
        for (int i = 0; i < n; i++) {
            while (idx < in.size() && in[idx].first < i) idx++;
            val[sz + i] = ll(in[idx].first - i) * in[idx - 1].second;
        }
        for (int i = sz - 1; i > 0; i--) val[i] = val[2 * i] + val[2 * i + 1];
    }

    void prop(int nd, int nl, int nr) {
        if (lzx[nd] >= 0) {
            if (nd < sz) {
                lzx[2 * nd] = lzx[2 * nd + 1] = lzx[nd];
                lzv[2 * nd] = lzv[2 * nd + 1] = lzv[nd];
            }
            val[nd] = ll(2 * lzx[nd] - nr - nl) * (nr - nl + 1) / 2 * lzv[nd];
            lzx[nd] = -1;
        }
    }

    void update(int l, int r, int x, int v, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return;
        if (l <= nl && nr <= r) {
            lzx[nd] = x;
            lzv[nd] = v;
            prop(nd, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        update(l, r, x, v, 2 * nd, nl, m);
        update(l, r, x, v, 2 * nd + 1, m + 1, nr);
        val[nd] = val[nd * 2] + val[nd * 2 + 1];
    }
    void update(int l, int r, int x, int v) { update(l, r, x, v, 1, 0, sz - 1); }

    ll query(int l, int r, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return val[nd];
        int m = (nl + nr) / 2;
        return query(l, r, nd * 2, nl, m) + query(l, r, nd * 2 + 1, m + 1, nr);
    }
    ll query(int l, int r) { return query(l, r, 1, 0, sz - 1); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    vector<pi> xv(m);
    for (int i = 0; i < m; i++) cin >> xv[i].first;
    for (int i = 0; i < m; i++) cin >> xv[i].second;
    xv.emplace_back(-1, 0);
    sort(xv.begin(), xv.end());

    map<int, int> hb;
    for (auto [x, v]: xv) hb.emplace(x, v);

    st_t st(n + 1, xv);
    while (q--) {
        int t, x, v; cin >> t >> x >> v;
        if (t == 1) {
            auto it = hb.lower_bound(x);
            st.update(prev(it)->first + 1, x, x, prev(it)->second);
            st.update(x + 1, it->first, it->first, v);
            hb[x] = v;
        } else {
            cout << st.query(x, v) << '\n';
        }
    }
}