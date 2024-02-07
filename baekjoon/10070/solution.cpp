#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;

typedef struct Segtree {
    int sz = 1;
    vector<int> val, lzl, lzu;
    Segtree(int n) {
        while (sz < n) sz *= 2;
        val = lzl = vector<int>(sz * 2, 0);
        lzu.resize(sz * 2, inf);
    }

    void prop(int nd, int nl, int nr) {
        if (lzl[nd] != 0 || lzu[nd] != inf) {
            if (nd < sz) {
                lzl[nd * 2] = min(max(lzl[nd * 2], lzl[nd]), lzu[nd]);
                lzu[nd * 2] = max(min(lzu[nd * 2], lzu[nd]), lzl[nd]);
                lzl[nd * 2 + 1] = min(max(lzl[nd * 2 + 1], lzl[nd]), lzu[nd]);
                lzu[nd * 2 + 1] = max(min(lzu[nd * 2 + 1], lzu[nd]), lzl[nd]);
            } else {
                val[nd] = min(max(val[nd], lzl[nd]), lzu[nd]);
            }
            lzl[nd] = 0;
            lzu[nd] = inf;
        }
    }

    void dfs(int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nl == nr) return;
        int m = (nl + nr) / 2;
        dfs(nd * 2, nl, m);
        dfs(nd * 2 + 1, m + 1, nr);
    }

    void update(int l, int r, int op, int v, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return;
        if (l <= nl && nr <= r) {
            if (op == 1) {
                lzl[nd] = max(lzl[nd], v);
                lzu[nd] = max(lzu[nd], v);
            } else {
                lzl[nd] = min(lzl[nd], v);
                lzu[nd] = min(lzu[nd], v);
            }
            prop(nd, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        update(l, r, op, v, nd * 2, nl, m);
        update(l, r, op, v, nd * 2 + 1, m + 1, nr);
    }
    void update(int l, int r, int op, int v) { update(l, r, op, v, 1, 0, sz - 1); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    st_t st(n);
    while (k--) {
        int op, l, r, h; cin >> op >> l >> r >> h;
        st.update(l, r, op, h);
    }
    st.dfs(1, 0, st.sz - 1);
    for (int i = 0; i < n; i++) cout << st.val[st.sz + i] << '\n';
}