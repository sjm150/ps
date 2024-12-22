#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct Segtree {
        int sz = 1;
        vector<int> val;
        Segtree(vector<int> &in) {
            while (sz < in.size()) sz *= 2;
            val.resize(sz * 2, 0);
            for (int i = 0; i < in.size(); i++) val[i + sz] = in[i];
            for (int i = sz - 1; i; i--) val[i] = max(val[i * 2], val[i * 2 + 1]);
        }
        int query(int l, int r, int nd, int nl, int nr) {
            if (r < nl || nr < l) return 0;
            if (l <= nl && nr <= r) return val[nd];
            int m = (nl + nr) / 2;
            return max(query(l, r, nd * 2, nl, m), query(l, r, nd * 2 + 1, m + 1, nr));
        }
        int query(int l, int r) { return query(l, r, 1, 0, sz - 1); }
    } st_t;

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (int &a: a) cin >> a;
        for (int &b: b) cin >> b;

        vector<int> h, p;
        for (int ai: a) {
            if (ai > a[0]) h.push_back(ai);
        }
        sort(h.begin(), h.end());
        for (int b: b) {
            if (b > a[0]) p.push_back(h.end() - lower_bound(h.begin(), h.end(), b));
        }
        sort(p.begin(), p.end(), greater<int>());
        p.resize(m, 0);

        st_t st(p);
        for (int k = 1; k <= m; k++) {
            long long cur = 0;
            for (int i = m - 1; i - k + 1 >= 0; i -= k) cur += st.query(i - k + 1, i) + 1;
            cout << cur << ' ';
        }
        cout << '\n';
    }
}