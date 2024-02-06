#include <bits/stdc++.h>
using namespace std;

typedef struct Segtree {
    int sz = 1;
    vector<int> val, lz;
    Segtree(int n) {
        while (sz < n) sz <<= 1;
        val = lz = vector<int>(sz * 2, 0);
    }

    void prop(int nd, int nl, int nr) {
        if (lz[nd]) {
            if (nd < sz) {
                lz[nd * 2] += lz[nd];
                lz[nd * 2 + 1] += lz[nd];
            } else {
                val[nd] += lz[nd];
            }
            lz[nd] = 0;
        }
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
    }
    void update(int l, int r, int x) { update(l, r, x, 1, 0, sz - 1); }

    int query(int i, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (i < nl || nr < i) return 0;
        if (nl == nr) return val[nd];
        int m = (nl + nr) / 2;
        return query(i, nd * 2, nl, m) + query(i, nd * 2 + 1, m + 1, nr);
    }
    int query(int i) { return query(i, 1, 0, sz - 1); }
} st_t;

vector<vector<int>> chld;
vector<int> l, r;
int ord;

void dfs(int cur) {
    l[cur] = ord++;
    for (int c: chld[cur]) dfs(c);
    if (chld[cur].empty()) r[cur] = l[cur];
    else r[cur] = r[chld[cur].back()];
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    chld.resize(n + 1);
    l = r = vector<int>(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        if (p > 0) chld[p].push_back(i);
    }
    dfs(1);

    st_t st(n);
    while (m--) {
        int c; cin >> c;
        if (c == 1) {
            int i, w; cin >> i >> w;
            st.update(l[i], r[i], w);
        } else {
            int i; cin >> i;
            cout << st.query(l[i]) << '\n';
        }
    }
}