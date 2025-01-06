#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    typedef struct Segtree {
        typedef struct Node {
            ll mx, ls, rs, sum;
            Node(ll v) { mx = ls = rs = sum = v; }
            Node(ll mx, ll ls, ll rs, ll sum): mx(mx), ls(ls), rs(rs), sum(sum) {}
            Node operator+(const Node &o) const {
                return Node(max(max(mx, o.mx), rs + o.ls), max(ls, sum + o.ls), max(o.rs, rs + o.sum), sum + o.sum);
            }
        } nd_t;
        int sz = 1;
        vector<nd_t> val;
        Segtree(int n) {
            while (sz < n) sz *= 2;
            val.resize(sz * 2, 0);
        }

        void update(int i, int x, int nd, int nl, int nr) {
            if (i < nl || nr < i) return;
            if (nl == nr) {
                val[nd] = Node(x);
                return;
            }
            int m = (nl + nr) / 2;
            update(i, x, nd * 2, nl, m);
            update(i, x, nd * 2 + 1, m + 1, nr);
            val[nd] = val[nd * 2] + val[nd * 2 + 1];
        }
        void update(int i, int x) { update(i, x, 1, 0, sz - 1); }

        ll query() { return val[1].mx; }
    } st_t;
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        st_t st(n), rst(n);
        auto upd = [&](int i) {
            if (0 < i && i < n) {
                st.update(i, a[i] - a[i - 1] - 1);
                rst.update(i, a[i - 1] - a[i] - 1);
            }
        };
        for (int i = 1; i < n; i++) upd(i);
        cout << max(st.query(), rst.query()) << '\n';
        while (q--) {
            int p, x; cin >> p >> x;
            p--;
            a[p] = x;
            upd(p);
            upd(p + 1);
            cout << max(st.query(), rst.query()) << '\n';
        }
    }
}