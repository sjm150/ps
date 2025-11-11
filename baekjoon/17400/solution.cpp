#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    typedef struct Segtree {
        int sz = 1;
        vector<ll> val;
        Segtree(vector<int> &a) {
            int n = a.size();
            while (sz < n) sz *= 2;
            val.resize(sz * 2, 0);
            for (int i = 0; i < n; i++) val[i + sz] = a[i];
            for (int i = sz - 1; i; i--) val[i] = val[i * 2] + val[i * 2 + 1];
        };
        ll query(int l, int r) {
            function<ll(int, int, int)> query = [&](int nd, int nl, int nr) {
                if (nr < l || r < nl) return 0ll;
                if (l <= nl && nr <= r) return val[nd];
                int m = (nl + nr) / 2;
                return query(nd * 2, nl, m) + query(nd * 2 + 1, m + 1, nr);
            };
            return query(1, 0, sz - 1);
        };
        void add(int i, int x) {
            val[i + sz] += x;
            for (int j = (i + sz) / 2; j; j /= 2) val[j] = val[j * 2] + val[j * 2 + 1];
        };
    } st_t;
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    for (int &c: c) cin >> c;
    for (int i = 0; i < n; i += 2) c[i] = -c[i];
    st_t st(c);
    while (q--) {
        int o, l, r;
        cin >> o >> l >> r;
        if (o == 1) cout << abs(st.query(l - 1, r - 1)) << '\n';
        else st.add(l - 1, r * (l % 2 ? -1 : 1));
    }
}