#include <bits/stdc++.h>
using namespace std;

typedef struct Segtree {
    int n;
    vector<int> val;
    Segtree(int n): n(n) {
        val.resize(4 * n, 0);
    }

    int query(int k) {
        int l = 0, r = n - 1, node = 0;
        while (l < r) {
            int lval = val[2 * node + 1];
            if (lval >= k) {
                r = (l + r) / 2;
                node = 2 * node + 1;
            } else {
                k -= lval;
                l = (l + r) / 2 + 1;
                node = 2 * node + 2;
            }
        }
        update(l, -1);
        return l;
    }

    int update(int i, int dv, int l, int r, int node) {
        if (i < l || r < i) return val[node];
        if (l == r) return val[node] += dv;
        int m = (l + r) / 2;
        return val[node] = update(i, dv, l, m, 2 * node + 1) + update(i, dv, m + 1, r, 2 * node + 2);
    }
    void update(int i, int dv) {
        update(i, dv, 0, n - 1, 0);
    }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    st_t st(1000001);
    while (n--) {
        int a; cin >> a;
        if (a == 1) {
            int b; cin >> b;
            cout << st.query(b) << '\n';
        } else {
            int b, c; cin >> b >> c;
            st.update(b, c);
        }
    }
}