#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;

typedef struct SegTree {
    int n;
    vector<int> val;
    SegTree(vector<int>& input) {
        n = input.size();
        val.resize(n * 4);
        init(0, n - 1, 0, input);
    }
    int init(int l, int r, int idx, vector<int>& input) {
        if (l == r) return val[idx] = input[l];
        int m = (l + r) / 2;
        int lval = init(l, m, 2 * idx + 1, input);
        int rval = init(m + 1, r, 2 * idx + 2, input);
        return val[idx] = ll(lval) * rval % mod;
    }

    int query(int l, int r, int idx, int ql, int qr) {
        if (r < ql || qr < l) return 1;
        if (ql <= l && r <= qr) return val[idx];
        int m = (l + r) / 2;
        int lval = query(l, m, 2 * idx + 1, ql, qr);
        int rval = query(m + 1, r, 2 * idx + 2, ql, qr);
        return ll(lval) * rval % mod;
    }
    int query(int l, int r) {
        return query(0, n - 1, 0, l, r);
    }

    int update(int l, int r, int idx, int i, int v) {
        if (i < l || r < i) return val[idx];
        if (l == r) return val[idx] = v;
        int m = (l + r) / 2;
        int lval = update(l, m, 2 * idx + 1, i, v);
        int rval = update(m + 1, r, 2 * idx + 2, i, v);
        return val[idx] = ll(lval) * rval % mod;
    }
    int update(int i, int v) {
        return update(0, n - 1, 0, i, v);
    }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> input(n);
    for (int i = 0; i < n; i++) cin >> input[i];
    st_t st(input);
    m += k;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) st.update(b - 1, c);
        else cout << st.query(b - 1, c - 1) << '\n';
    }
}