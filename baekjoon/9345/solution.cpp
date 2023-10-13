#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int inf = 123456789;

typedef struct SegTree {
    int n;
    vector<pi> val;

    SegTree(vector<int>& input) {
        n = input.size();
        val = vector<pi>(4 * n);
        init(input, 0, n - 1, 0);
    }
    pi init(vector<int>& input, int l, int r, int node) {
        if (l == r) return val[node] = {input[l], input[l]};
        int m = (l + r) / 2;
        auto [lmin, lmax] = init(input, l, m, node * 2 + 1);
        auto [rmin, rmax] = init(input, m + 1, r, node * 2 + 2);
        return val[node] = {min(lmin, rmin), max(lmax, rmax)};
    }

    pi query(int ql, int qr, int l, int r, int node) {
        if (r < ql || qr < l) return {inf, -inf};
        if (ql <= l && r <= qr) return val[node];
        int m = (l + r) / 2;
        auto [lmin, lmax] = query(ql, qr, l, m, node * 2 + 1);
        auto [rmin, rmax] = query(ql, qr, m + 1, r, node * 2 + 2);
        return {min(lmin, rmin), max(lmax, rmax)};
    }
    pi query(int l, int r) {
        return query(l, r, 0, n - 1, 0);
    }

    pi update(int i, int x, int l, int r, int node) {
        if (i < l || r < i) return val[node];
        if (l == r) return val[node] = {x, x};
        int m = (l + r) / 2;
        auto [lmin, lmax] = update(i, x, l, m, node * 2 + 1);
        auto [rmin, rmax] = update(i, x, m + 1, r, node * 2 + 2);
        return val[node] = {min(lmin, rmin), max(lmax, rmax)};
    }
    void update(int i, int x) {
        update(i, x, 0, n - 1, 0);
    }
} st_t;

void swap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> input(n);
        iota(input.begin(), input.end(), 0);
        st_t st(input);
        while (k--) {
            int q, a, b; cin >> q >> a >> b;
            if (q == 0) {
                st.update(a, input[b]);
                st.update(b, input[a]);
                swap(input[a], input[b]);
            } else {
                if (st.query(a, b) == pi(a, b)) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}