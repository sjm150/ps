#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct Segtree {
        vector<int> val, lz;
        int sz = 1;
        Segtree(int n) {
            while (sz < n) sz *= 2;
            val.resize(sz * 2, 0);
            lz.resize(sz * 2, 0);
        }

        void prop(int nd, int nl, int nr) {
            if (lz[nd]) {
                if (nd < sz) {
                    lz[nd * 2] += lz[nd];
                    lz[nd * 2 + 1] += lz[nd];
                }
                val[nd] += lz[nd];
                lz[nd] = 0;
            }
        }

        void add(int l, int r, int x, int nd, int nl, int nr) {
            prop(nd, nl, nr);
            if (nr < l || r < nl) return;
            if (l <= nl && nr <= r) {
                lz[nd] += x;
                prop(nd, nl, nr);
                return;
            }
            int m = (nl + nr) / 2;
            add(l, r, x, nd * 2, nl, m);
            add(l, r, x, nd * 2 + 1, m + 1, nr);
            val[nd] = min(val[nd * 2], val[nd * 2 + 1]);
        }
        void add(int l, int r, int x) { add(l, min(sz - 1, r), x, 1, 0, sz - 1); }

        int query(int l, int r, int nd, int nl, int nr) {
            prop(nd, nl, nr);
            if (nr < l || r < nl) return inf;
            if (l <= nl && nr <= r) return val[nd];
            int m = (nl + nr) / 2;
            return min(query(l, r, nd * 2, nl, m), query(l, r, nd * 2 + 1, m + 1, nr));
        }
        int query(int l, int r) { return query(l, r, 1, 0, sz - 1); }
    } st_t;

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        st_t st(n + 2);
        unordered_map<int, int> cnt;
        int mex = 0;
        st.add(0, 0, -1);
        for (int a: a) {
            cnt[a]++;
            if (a <= mex && cnt[a] == 1) {
                st.add(a, a, inf);
                st.add(0, a, 1);
            } else {
                st.add(0, (a - 1) / 2, 1);
            }

            for (;;) {
                if (st.query(0, mex) < 0) break;
                mex++;
                if (cnt[mex]) {
                    st.add(0, (mex - 1) / 2, -1);
                    st.add(mex, mex, inf);
                } else {
                    st.add(0, mex, -1);
                }
            }

            cout << mex << ' ';
        }
        cout << '\n';
    }
}