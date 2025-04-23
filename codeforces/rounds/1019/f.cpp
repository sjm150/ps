#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct Segtree {
        int sz = 1;
        vector<int> val, lz;
        Segtree(int n) {
            while (sz < n) sz *= 2;
            val.resize(sz * 2, 0);
            lz.resize(sz * 2, 0);
        }
        
        void prop(int nd, int nl, int nr) {
            if (lz[nd]) {
                if (nd < sz) {
                    lz[nd * 2] = max(lz[nd * 2], lz[nd]);
                    lz[nd * 2 + 1] = max(lz[nd * 2 + 1], lz[nd]);
                }
                val[nd] = max(val[nd], lz[nd]);
                lz[nd] = 0;
            }
        }

        void update(int nd, int nl, int nr, int l, int r, int v) {
            prop(nd, nl, nr);
            if (nr < l || r < nl) return;
            if (l <= nl && nr <= r) {
                lz[nd] = max(lz[nd], v);
                prop(nd, nl, nr);
                return;
            }
            int m = (nl + nr) / 2;
            update(nd * 2, nl, m, l, r, v);
            update(nd * 2 + 1, m + 1, nr, l, r, v);
            val[nd] = max(val[nd * 2], val[nd * 2 + 1]);
        }
        void update(int l, int r, int v) { update(1, 0, sz - 1, l, r, v); }

        int query(int nd, int nl, int nr, int l, int r) {
            prop(nd, nl, nr);
            if (nr < l || r < nl) return 0;
            if (l <= nl && nr <= r) return val[nd];
            int m = (nl + nr) / 2;
            return max(query(nd * 2, nl, m, l, r), query(nd * 2 + 1, m + 1, nr, l, r));
        }
        int query(int l, int r) { return query(1, 0, sz - 1, l, r); }
    } st_t;

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        vector<vector<int>> l(k, vector<int>(n));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) l[i][j] = (a[j] & (1 << i)) ? j : (j > 0 ? l[i][j - 1] : -1);
        }

        st_t st(n);
        for (int r = 0; r < n; r++) {
            vector<int> cnd;
            for (int i = 0; i <= min(r, 1); i++) cnd.push_back(i);
            for (int i = 0; i < k; i++) {
                for (int l: {l[i][r], l[i][r] + 1, l[i][r] + 2}) {
                    if (0 <= l && l <= r) cnd.push_back(l);
                }
            }
            sort(cnd.begin(), cnd.end());
            cnd.erase(unique(cnd.begin(), cnd.end()), cnd.end());
            for (int c: cnd) {
                int v = 0;
                for (int i = 0; i < k; i++) {
                    if (l[i][r] == c) {
                        if ((c + r) % 2 == 0) v |= 1 << i;
                    } else {
                        if ((max(l[i][r], c) + r) % 2) v |= 1 << i;
                    }
                }
                st.update(c, r, v);
            }
        }

        for (int i = 0; i < n; i++) cout << st.query(i, i) << ' ';
        cout << '\n';
    }
}