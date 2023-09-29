#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 1;

typedef struct SegTree {
    int n;
    vector<int> a;
    vector<int> val;

    SegTree(vector<int>& input) {
        n = input.size();
        a = vector<int>(input);
        a.push_back(inf);
        val = vector<int>(4 * n);
        init(0, n - 1, 0);
    }
    int init(int l, int r, int idx) {
        if (l == r) return val[idx] = l;
        int m = (l + r) / 2;
        int lv = init(l, m, idx * 2 + 1);
        int rv = init(m + 1, r, idx * 2 + 2);
        if (a[lv] <= a[rv]) return val[idx] = lv;
        else return val[idx] = rv;
    }

    int query(int ql, int qr, int l, int r, int idx) {
        if (r < ql || qr < l) return n;
        if (ql <= l && r <= qr) return val[idx];
        int m = (l + r) / 2;
        int lv = query(ql, qr, l, m, idx * 2 + 1);
        int rv = query(ql, qr, m + 1, r, idx * 2 + 2);
        if (a[lv] <= a[rv]) return lv;
        else return rv;
    }
    int query(int l, int r) {
        return query(l, r, 0, n - 1, 0);
    }

    int update(int i, int l, int r, int idx) {
        if (i < l || r < i || l == r) return val[idx];
        int m = (l + r) / 2;
        int lv = update(i, l, m, idx * 2 + 1);
        int rv = update(i, m + 1, r, idx * 2 + 2);
        if (a[lv] <= a[rv]) return val[idx] = lv;
        else return val[idx] = rv;
    }
    void update(int i, int v) {
        a[i] = v;
        update(i, 0, n - 1, 0);
    }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    st_t st(a);
    int m; cin >> m;
    while (m--) {
        int q, i, j; cin >> q >> i >> j;
        if (q == 1) st.update(i - 1, j);
        else cout << st.query(i - 1, j - 1) + 1 << '\n';
    }
}