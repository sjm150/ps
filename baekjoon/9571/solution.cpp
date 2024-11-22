#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct Segtree {
        int sz = 1;
        vector<int> val;
        Segtree(vector<pair<int, int>> &in) {
            while (sz < in.size()) sz *= 2;
            val.resize(sz * 2, 0);
            for (int i = 0; i < in.size(); i++) val[i + sz] = in[i].second;
            for (int i = sz - 1; i; i--) val[i] = max(val[i * 2], val[i * 2 + 1]);
        }
        int query(int l, int r, int nd, int nl, int nr) {
            if (nr < l || r < nl) return 0;
            if (l <= nl && nr <= r) return val[nd];
            int m = (nl + nr) / 2;
            return max(query(l, r, nd * 2, nl, m), query(l, r, nd * 2 + 1, m + 1, nr));
        }
        int query(int l, int r) { return query(l, r, 1, 0, sz - 1); }
    } st_t;

    int n, d; cin >> n >> d;
    vector<pair<int, int>> xh(n);
    for (auto &[x, h]: xh) cin >> x >> h;
    sort(xh.begin(), xh.end());

    st_t st(xh);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto [x, h] = xh[i];
        if (st.query(lower_bound(xh.begin(), xh.end(), make_pair(x - d, 0)) - xh.begin(), i) >= 2 * h && st.query(i, upper_bound(xh.begin(), xh.end(), make_pair(x + d, int(2e9))) - xh.begin() - 1) >= 2 * h) ans++;
    }
    cout << ans << '\n';
}