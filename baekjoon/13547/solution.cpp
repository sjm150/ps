#include <bits/stdc++.h>
using namespace std;

typedef struct Segtree {
    int sz = 1;
    vector<vector<int>> val;
    Segtree(vector<int> &a) {
        while (sz < a.size()) sz *= 2;
        val.resize(sz * 2);
        for (int i = 0; i < sz; i++) val[sz + i].push_back(a[i]);
        for (int i = sz - 1; i; i--) {
            vector<int> &dst = val[i], &a = val[i * 2], &b = val[i * 2 + 1];
            int ai = 0, bi = 0;
            while (ai < a.size() && bi < b.size()) {
                if (a[ai] < b[bi]) dst.push_back(a[ai++]);
                else dst.push_back(b[bi++]);
            }
            while (ai < a.size()) dst.push_back(a[ai++]);
            while (bi < b.size()) dst.push_back(b[bi++]);
        }
    }

    int query(int l, int r, int nd, int nl, int nr) {
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return upper_bound(val[nd].begin(), val[nd].end(), r) - val[nd].begin();
        int m = (nl + nr) / 2;
        return query(l, r, nd * 2, nl, m) + query(l, r, nd * 2 + 1, m + 1, nr);
    }
    int query(int l, int r) { return query(l, r, 1, 0, sz - 1); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    vector<int> nxt(n);
    map<int, int> pre;
    for (int i = 0; i < n; i++) {
        auto it = pre.find(a[i]);
        if (it != pre.end()) {
            nxt[it->second] = i;
            it->second = i;
        } else {
            pre.emplace(a[i], i);
        }
    }
    for (auto &[a, i]: pre) nxt[i] = n;

    st_t st(nxt);
    int m; cin >> m;
    while (m--) {
        int i, j; cin >> i >> j;
        cout << j - i + 1 - st.query(i - 1, j - 1) << '\n';
    }
}