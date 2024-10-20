#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e18;

typedef struct Segtree {
    int sz = 1;
    vector<ll> val, lz;
    Segtree(int n) {
        while (sz < n) sz *= 2;
        val.resize(sz * 2, inf);
        lz.resize(sz * 2, inf);
    }

    void prop(int nd, int nl, int nr) {
        if (lz[nd] < inf) {
            if (nd < sz) {
                lz[nd * 2] = min(lz[nd * 2], lz[nd]);
                lz[nd * 2 + 1] = min(lz[nd * 2 + 1], lz[nd]);
            }
            val[nd] = min(val[nd], lz[nd]);
            lz[nd] = inf;
        }
    }

    void update(int l, int r, ll v, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return;
        if (l <= nl && nr <= r) {
            lz[nd] = min(lz[nd], v);
            prop(nd, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        update(l, r, v, nd * 2, nl, m);
        update(l, r, v, nd * 2 + 1, m + 1, nr);
        val[nd] = min(val[nd * 2], val[nd * 2 + 1]);
    }
    void update(int l, int r, ll v) { update(l, r, v, 1, 0, sz - 1); }

    ll query(int i, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (i < nl || nr < i) return inf;
        if (nl == nr) return val[nd];
        int m = (nl + nr) / 2;
        return min(query(i, nd * 2, nl, m), query(i, nd * 2 + 1, m + 1, nr));
    }
    ll query(int i) { return query(i, 1, 0, sz - 1); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int &a: a) cin >> a;
        for (int &b: b) {
            cin >> b;
            b--;
        }

        st_t st(n);
        st.update(0, 0, 0);
        for (int i = 0; i < n; i++) {
            if (i >= b[i]) continue;
            st.update(0, b[i], st.query(i) + a[i]);
        }

        ll sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            ans = max(ans, sum - st.query(i));
        }
        cout << ans << '\n';
    }
}