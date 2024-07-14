#include <bits/stdc++.h>
using namespace std;

typedef struct Segtree {
    int sz = 1;
    vector<vector<int>> val;
    Segtree(vector<int> &a) {
        while (sz < a.size()) sz *= 2;
        val.resize(sz * 2);
        for (int i = 0; i < a.size(); i++) val[i + sz].push_back(a[i]);
        for (int i = sz - 1; i; i--) merge(val[i], val[i * 2], val[i * 2 + 1]);
    }

    void merge(vector<int> &dst, vector<int> &a, vector<int> &b) {
        int ai = 0, bi = 0;
        while (ai < a.size() && bi < b.size()) {
            if (a[ai] < b[bi]) dst.push_back(a[ai++]);
            else dst.push_back(b[bi++]);
        }
        while (ai < a.size()) dst.push_back(a[ai++]);
        while (bi < b.size()) dst.push_back(b[bi++]);
    }

    int query(int k, int l, int r, int nd, int nl, int nr) {
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return val[nd].end() - upper_bound(val[nd].begin(), val[nd].end(), k);
        int m = (nl + nr) / 2;
        return query(k, l, r, nd * 2, nl, m) + query(k, l, r, nd * 2 + 1, m + 1, nr);
    }
    int query(int k, int l, int r) { return query(k, l, r, 1, 0, sz - 1); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    st_t st(a);
    int m; cin >> m;
    while (m--) {
        int i, j, k; cin >> i >> j >> k;
        cout << st.query(k, i - 1, j - 1) << '\n';
    }
}