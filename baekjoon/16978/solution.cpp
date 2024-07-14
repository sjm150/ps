#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef struct Segtree {
    int sz = 1;
    vector<vector<pair<int, ll>>> val;
    Segtree(vector<int> &a) {
        while (sz < a.size()) sz *= 2;
        val.resize(sz * 2, vector<pair<int, ll>>(1, {0, 0}));
        for (int i = 0; i < a.size(); i++) val[sz + i][0].second = a[i];
        for (int i = sz - 1; i; i--) val[i][0].second = val[i * 2][0].second + val[i * 2 + 1][0].second;
    }

    void update(int k, int i, int v) {
        int nd = sz + i;
        ll dv = v - val[nd].back().second;
        for (; nd; nd /= 2) val[nd].emplace_back(k, val[nd].back().second + dv);
    }

    ll query(int k, int l, int r, int nd, int nl, int nr) {
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return prev(lower_bound(val[nd].begin(), val[nd].end(), make_pair(k + 1, 0ll)))->second;
        int m = (nl + nr) / 2;
        return query(k, l, r, nd * 2, nl, m) + query(k, l, r, nd * 2 + 1, m + 1, nr);
    }
    ll query(int k, int l, int r) { return query(k, l, r, 1, 0, sz - 1); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    st_t st(a);
    int m; cin >> m;
    int k = 1;
    while (m--) {
        int q; cin >> q;
        if (q == 1) {
            int i, v; cin >> i >> v;
            st.update(k++, i - 1, v);
        } else {
            int k, i, j; cin >> k >> i >> j;
            cout << st.query(k, i - 1, j - 1) << '\n';
        }
    }
}