#include <bits/stdc++.h>
using namespace std;

typedef struct Segtree {
    int sz = 1;
    vector<int> val;
    Segtree(int n) {
        while (sz < n) sz *= 2;
        val.resize(sz * 2, 0);
    }

    void update(int i, int x) {
        i += sz;
        val[i] = x;
        for (i /= 2; i; i /= 2) val[i] = max(val[i * 2], val[i * 2 + 1]);
    }

    int query(int l, int r, int nd, int nl, int nr) {
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return val[nd];
        int m = (nl + nr) / 2;
        return max(query(l, r, nd * 2, nl, m), query(l, r, nd * 2 + 1, m + 1, nr));
    }
    int query(int l, int r) { return query(max(0, l), min(sz - 1, r), 1, 0, sz - 1); }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k, d; cin >> n >> k >> d;
    vector<int> s(n);
    for (int &s: s) cin >> s;
    int mx = *max_element(s.begin(), s.end());
    st_t st(mx + 1);
    vector<int> cnt(k, 0);
    int ans = 0;
    for (int s: s) {
        int cur = max(st.query(s - d, s + d), cnt[s % k]) + 1;
        ans = max(ans, cur);
        st.update(s, cur);
        cnt[s % k] = cur;
    }
    cout << ans << '\n';
}