#include <bits/stdc++.h>
using namespace std;

typedef struct Segtree {
    int sz = 1;
    vector<int> val, lz;
    Segtree(int n) {
        while (sz < n) sz *= 2;
        val = lz = vector<int>(sz * 2, 0);
        for (int i = 0; i < n; i++) val[sz + i] = i - n;
        for (int i = sz - 1; i; i--) val[i] = min(val[i * 2], val[i * 2 + 1]);
    }

    void prop(int nd, int nl, int nr) {
        if (lz[nd] == 0) return;
        if (nd < sz) {
            lz[nd * 2] += lz[nd];
            lz[nd * 2 + 1] += lz[nd];
        }
        val[nd] += lz[nd];
        lz[nd] = 0;
    }

    void update(int l, int r, int x, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return;
        if (l <= nl && nr <= r) {
            lz[nd] += x;
            prop(nd, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        update(l, r, x, nd * 2, nl, m);
        update(l, r, x, nd * 2 + 1, m + 1, nr);
        val[nd] = min(val[nd * 2], val[nd * 2 + 1]);
    }
    void update(int l, int r, int x) { update(l, r, x, 1, 0, sz - 1); }

    bool query() {
        prop(1, 0, sz - 1);
        return val[1] >= 0;
    }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    st_t st(n);
    vector<int> a(n);
    for (int &a: a) {
        cin >> a;
        st.update(0, min(a, n) - 1, 1);
    }
    cout << (st.query() ? "TAK\n" : "NIE\n");
    int m; cin >> m;
    while (m--) {
        int j, w; cin >> j >> w;
        j--;
        st.update(0, min(a[j], n) - 1, -1);
        a[j] = w;
        st.update(0, min(a[j], n) - 1, 1);
        cout << (st.query() ? "TAK\n" : "NIE\n");
    }
}