#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

typedef struct Segtree {
    int sz = 1;
    vector<int> val;
    Segtree(int n) {
        while (sz < n) sz *= 2;
        val.resize(2 * sz, inf);
        for (int i = 0; i < n; i++) val[sz + i] = -1;
        for (int i = sz - 1; i; i--) val[i] = min(val[2 * i], val[2 * i + 1]);
    }

    void update(int nd, int nl, int nr, int i, int x) {
        if (i < nl || nr < i) return;
        if (nl == nr) {
            val[nd] = x;
            return;
        }
        int m = (nl + nr) / 2;
        update(nd * 2, nl, m, i, x);
        update(nd * 2 + 1, m + 1, nr, i, x);
        val[nd] = min(val[2 * nd], val[2 * nd + 1]);
    }
    void update(int i, int x) { update(1, 0, sz - 1, i, x); }

    int query() { return val[1]; }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int q, mod; cin >> q >> mod;

    if (q <= mod) {
        while (q--) {
            int c; cin >> c;
            if (c == 1) cin >> c;
            else if (c == 3) cout << -1 << '\n';
        }
        return 0;
    }

    vector<int> arr;
    vector<vector<int>> idx(mod, vector<int>(1, -1));
    st_t st(mod);

    while (q--) {
        int c; cin >> c;
        if (c == 1) {
            int num; cin >> num;
            num %= mod;
            st.update(num, arr.size());
            idx[num].push_back(arr.size());
            arr.push_back(num);
        } else if (c == 2) {
            if (!arr.empty()) {
                int num = arr.back(); arr.pop_back();
                idx[num].pop_back();
                st.update(num, idx[num].back());
            }
        } else {
            int m = st.query();
            if (m >= 0) cout << arr.size() - m << '\n';
            else cout << -1 << '\n';
        }
    }
}