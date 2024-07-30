#include <bits/stdc++.h>
using namespace std;

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
            val[nd] = Node(val[nd].mx + x);
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

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<tuple<int, int, int>> xyw(n);
    for (auto &[x, y, w]: xyw) cin >> x >> y >> w;
    sort(xyw.begin(), xyw.end());
    vector<int> ys;
    for (auto &[x, y, w]: xyw) ys.push_back(y);
    sort(ys.begin(), ys.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && get<0>(xyw[i - 1]) == get<0>(xyw[i])) continue;
        st_t st(n);
        for (int j = i; j < n; j++) {
            auto &[x, y, w] = xyw[j];
            st.update(lower_bound(ys.begin(), ys.end(), y) - ys.begin(), w);
            if (j == n - 1 || x != get<0>(xyw[j + 1])) ans = max(ans, st.query());
        }
    }
    cout << ans << '\n';
}