#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 2e18;

typedef struct Segtree {
    int sz = 1;
    vector<int> val, lz;
    Segtree(int n) {
        while (sz < n) sz *= 2;
        val = lz = vector<int>(sz * 2, 1);
    }

    void prop(int nd, int nl, int nr) {
        if (lz[nd] != 1) {
            if (nd < sz) {
                lz[nd * 2] *= lz[nd];
                lz[nd * 2 + 1] *= lz[nd];
            } else {
                val[nd] *= lz[nd];
            }
            lz[nd] = 1;
        }
    }

    void update(int l, int r, int x, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return;
        if (l <= nl && nr <= r) {
            lz[nd] *= x;
            prop(nd, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        update(l, r, x, nd * 2, nl, m);
        update(l, r, x, nd * 2 + 1, m + 1, nr);
    }
    void update(int l, int r, int x) { update(l, r, x, 1, 0, sz - 1); }

    int query(int i, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < i || i < nl) return 1;
        if (nl == nr) return val[nd];
        int m = (nl + nr) / 2;
        return query(i, nd * 2, nl, m) * query(i, nd * 2 + 1, m + 1, nr);
    }
    int query(int i) { return query(i, 1, 0, sz - 1); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int q; cin >> q;
    vector<vector<ll>> qs(q);
    set<ll> occ = {-inf - 1, -inf, inf, inf + 1};
    for (auto &q: qs) {
        int t; cin >> t;
        if (t == 1) {
            ll a, b; cin >> a >> b;
            q = {t, a, b};
        } else {
            ll c; cin >> c;
            occ.insert(c);
            q = {t, c};
        }
    }

    map<ll, int> idx;
    int n = 0;
    for (ll c: occ) idx[c] = n++;

    st_t st(n);
    auto update = [&](ll a, ll b) {
        if (a == 0) {
            st.update(0, n - 1, (b == 0 ? 0 : b / abs(b)));
            return;
        }
        ll x;
        if ((a < 0 && b < 0) || (a > 0 && b > 0)) x = abs(b) / abs(a) * (-1);
        else x = (abs(b) + abs(a) - 1) / abs(a);
        auto it = idx.lower_bound(x);
        if (abs(b) % abs(a) == 0 && it->first == x) {
            st.update(0, it->second - 1, -a / abs(a));
            st.update(it->second, it->second, 0);
            st.update(it->second + 1, n - 1, a / abs(a));
        } else {
            st.update(0, it->second - 1, -a / abs(a));
            st.update(it->second, n - 1, a / abs(a));
        }
    };

    for (auto &q: qs) {
        if (q[0] == 1) {
            update(q[1], q[2]);
        } else {
            int r = st.query(idx[q[1]]);
            if (r < 0) cout << "-\n";
            else if (r > 0) cout << "+\n";
            else cout << "0\n";
        }
    }
}