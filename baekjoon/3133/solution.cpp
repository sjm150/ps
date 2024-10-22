#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    const int mod = 1e9 + 7;
    typedef struct Segtree {
        int sz = 1;
        vector<pi> val;
        Segtree(int n) {
            while (sz < n) sz *= 2;
            val.resize(sz * 2, make_pair(0, 0));
        }

        pi merge(pi a, pi b) {
            if (a.first == b.first) return make_pair(a.first, (a.second + b.second) % mod);
            else if (a.first > b.first) return a;
            else return b;
        }

        void update(int i, pi v, int nd, int nl, int nr) {
            if (i < nl || nr < i) return;
            if (nl == nr) {
                val[nd] = merge(val[nd], v);
                return;
            }
            int m = (nl + nr) / 2;
            update(i, v, nd * 2, nl, m);
            update(i, v, nd * 2 + 1, m + 1, nr);
            val[nd] = merge(val[nd * 2], val[nd * 2 + 1]);
        }
        void update(int i, pi v) { update(i, v, 1, 0, sz - 1); }

        pi query(int l, int r, int nd, int nl, int nr) {
            if (nr < l || r < nl) return make_pair(0, 0);
            if (l <= nl && nr <= r) return val[nd];
            int m = (nl + nr) / 2;
            return merge(query(l, r, nd * 2, nl, m), query(l, r, nd * 2 + 1, m + 1, nr));
        }
        pi query(int l, int r) {
            if (r < l) return make_pair(0, 0);
            return query(l, r, 1, 0, sz - 1);
        }
    } st_t;

    int n; cin >> n;
    vector<pi> xy(n);
    for (auto &[x, y]: xy) cin >> x >> y;
    sort(xy.begin(), xy.end(), [](pi &a, pi &b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    vector<int> ys;
    for (auto [x, y]: xy) ys.push_back(y);
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    st_t st(ys.size());
    for (auto [x, y]: xy) {
        int yi = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
        auto [len, cnt] = st.query(0, yi - 1);
        if (len == 0) cnt++;
        len++;
        st.update(yi, make_pair(len, cnt));
    }

    auto [len, cnt] = st.query(0, ys.size() - 1);
    cout << len << '\n' << cnt << '\n';
}