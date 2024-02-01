#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Segtree {
    int n;
    vector<ll> val, lz;
    Segtree(vector<ll>& in) {
        n = 1;
        while (n < in.size()) n <<= 1;
        val.resize(2 * n);
        lz.resize(2 * n, 0);
        for (int i = 0; i < in.size(); i++) val[n + i] = in[i];
        for (int i = n - 1; i > 0; i--) val[i] = val[2 * i] + val[2 * i + 1];
    }

    void prop(int cur, int l, int r) {
        if (lz[cur]) {
            if (cur < n) {
                lz[2 * cur] += lz[cur];
                lz[2 * cur + 1] += lz[cur];
            }
            val[cur] += lz[cur] * (r - l + 1);
            lz[cur] = 0;
        }
    }

    void update(int cur, int l, int r, int ql, int qr, ll x) {
        prop(cur, l, r);
        if (r < ql || qr < l) return;
        if (ql <= l && r <= qr) {
            lz[cur] += x;
            prop(cur, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(2 * cur, l, m, ql, qr, x);
        update(2 * cur + 1, m + 1, r, ql, qr, x);
        val[cur] = val[2 * cur] + val[2 * cur + 1];
    }
    void update(int l, int r, ll x) { update(1, 0, n - 1, l, r, x); }

    ll query(int cur, int l, int r, int ql, int qr) {
        prop(cur, l, r);
        if (r < ql || qr < l) return 0;
        if (ql <= l && r <= qr) return val[cur];
        int m = (l + r) / 2;
        return query(2 * cur, l, m, ql, qr) + query(2 * cur + 1, m + 1, r, ql, qr);
    }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vector<ll> in(n);
    for (int i = 0; i < n; i++) cin >> in[i];
    st_t st(in);

    m += k;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            ll d; cin >> d;
            st.update(b - 1, c - 1, d);
        } else {
            cout << st.query(b - 1, c - 1) << '\n';
        }
    }
}