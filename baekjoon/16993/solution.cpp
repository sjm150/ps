#include <bits/stdc++.h>
using namespace std;

const int inf = 1e4;

typedef struct Segtree {
    typedef struct Node {
        int mx, ls, rs, sum;
        Node(int v) { mx = ls = rs = sum = v; }
        Node(int mx, int ls, int rs, int sum): mx(mx), ls(ls), rs(rs), sum(sum) {}
        Node operator+(const Node &o) const {
            return Node(max(max(mx, o.mx), rs + o.ls), max(ls, sum + o.ls), max(o.rs, rs + o.sum), sum + o.sum);
        }
    } nd_t;
    int sz = 1;
    vector<nd_t> val;
    Segtree(vector<int> &a) {
        while (sz < a.size()) sz *= 2;
        val.resize(sz * 2, -inf);
        for (int i = 0; i < a.size(); i++) val[sz + i] = Node(a[i]);
        for (int i = sz - 1; i; i--) val[i] = val[i * 2] + val[i * 2 + 1];
    }

    nd_t query(int l, int r, int nd, int nl, int nr) {
        if (nr < l || r < nl) return Node(-inf);
        if (l <= nl && nr <= r) return val[nd];
        int m = (nl + nr) / 2;
        return query(l, r, nd * 2, nl, m) + query(l, r, nd * 2 + 1, m + 1, nr);
    }
    int query(int l, int r) { return query(l, r, 1, 0, sz - 1).mx; }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    st_t st(a);
    int m; cin >> m;
    while (m--) {
        int i, j; cin >> i >> j;
        cout << st.query(i - 1, j - 1) << '\n';
    }
}