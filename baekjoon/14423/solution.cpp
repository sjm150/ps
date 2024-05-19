#include <bits/stdc++.h>
using namespace std;

typedef struct Segtree {
    int sz = 1;
    vector<int> val, nval;

    Segtree(int n) {
        while (sz < n) sz *= 2;
        val.resize(n, 0);
        nval.resize(sz * 2, 0);
        for (int i = 1; i < n; i++) nval[sz + i] = i;
    }

    void init() {
        for (int i = sz - 1; i; i--) {
            nval[i] = val[nval[i * 2]] > val[nval[i * 2 + 1]] ? nval[i * 2] : nval[i * 2 + 1];
        }
    }

    void update(int x, int dv) {
        val[x] += dv;
        for (int i = (sz + x) / 2; i >= 1; i = i / 2) {
            nval[i] = val[nval[i * 2]] > val[nval[i * 2 + 1]] ? nval[i * 2] : nval[i * 2 + 1];
        }
    }

    int query() { return val[nval[1]]; }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> c(n);
    for (int &c: c) cin >> c;

    vector<int> cnt(m + 1, 0);
    for (int c: c) cnt[c]++;
    st_t st(m + 1);
    for (int i = 1; i <= m; i++) st.val[i] = cnt[i];
    st.init();

    vector<vector<vector<int>>> mch(2, vector<vector<int>>(m + 1));
    for (int b = 0; b < 2; b++) {
        for (int i = b; i + 1 < n; i += 2) {
            if (c[i] == c[i + 1]) continue;
            mch[b][c[i]].push_back(c[i + 1]);
            mch[b][c[i + 1]].push_back(c[i]);
        }
    }

    vector<int> ans(m + 1, n);
    for (auto &mch: mch) {
        for (int i = 1; i <= m; i++) {
            st.update(i, -cnt[i]);
            for (int c: mch[i]) st.update(c, -1);
            ans[i] = min(ans[i], n - cnt[i] - st.query());
            for (int c: mch[i]) st.update(c, 1);
            st.update(i, cnt[i]);
        }
    }

    for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
}