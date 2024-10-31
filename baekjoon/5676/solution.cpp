#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct Segtree {
        int sz = 1;
        vector<int> val;
        Segtree(vector<int> &x) {
            while (sz < x.size()) sz *= 2;
            val.resize(sz * 2, 1);
            for (int i = 0; i < x.size(); i++) val[sz + i] = x[i] ? x[i] / abs(x[i]) : 0;
            for (int i = sz - 1; i; i--) val[i] = val[2 * i] * val[2 * i + 1];
        }

        void update(int i, int v) {
            int nd = sz + i;
            val[nd] = v;
            for (nd /= 2; nd; nd /= 2) val[nd] = val[2 * nd] * val[2 * nd + 1];
        }

        int query(int l, int r, int nd, int nl, int nr) {
            if (nr < l || r < nl) return 1;
            if (l <= nl && nr <= r) return val[nd];
            int m = (nl + nr) / 2;
            return query(l, r, nd * 2, nl, m) * query(l, r, nd * 2 + 1, m + 1, nr);
        }
        int query(int l, int r) { return query(l, r, 1, 0, sz - 1); }
    } st_t;

    int n, k;
    while (cin >> n) {
        cin >> k;
        vector<int> x(n);
        for (int &x: x) cin >> x;
        st_t st(x);
        while (k--) {
            char c; cin >> c;
            if (c == 'C') {
                int i, v; cin >> i >> v;
                st.update(i - 1, v ? v / abs(v) : 0);
            } else {
                int l, r; cin >> l >> r;
                int v = st.query(l - 1, r - 1);
                cout << (v ? (v > 0 ? '+' : '-') : '0');
            }
        }
        cout << '\n';
    }
}