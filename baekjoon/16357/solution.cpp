#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

typedef struct Segtree {
    int sz = 1;
    vector<int> val, lz;
    Segtree(int n) {
        while (sz < n) sz *= 2;
        val = lz = vector<int>(sz * 2, 0);
    }

    void prop(int nd, int nl, int nr) {
        if (lz[nd]) {
            if (nd < sz) {
                lz[nd * 2] += lz[nd];
                lz[nd * 2 + 1] += lz[nd];
            }
            val[nd] += lz[nd];
            lz[nd] = 0;
        }
    }

    void incr(int l, int r, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return;
        if (l <= nl && nr <= r) {
            lz[nd]++;
            prop(nd, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        incr(l, r, nd * 2, nl, m);
        incr(l, r, nd * 2 + 1, m + 1, nr);
        val[nd] = max(val[nd * 2], val[nd * 2 + 1]);
    }
    void incr(int l, int r) { incr(l, r, 1, 0, sz - 1); }

    int query() {
        prop(1, 0, sz - 1);
        return val[1];
    }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pi> line;
    map<int, int> idx;
    while (n--) {
        int ux, uy, vx, vy; cin >> ux >> uy >> vx >> vy;
        line.emplace_back(vy, uy);
        idx[uy] = 0;
        idx[vy] = 0;
    }
    sort(line.begin(), line.end());

    n = 0;
    for (auto &[k, v]: idx) v = n++;
    st_t st(n);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int ans = 0;
    for (auto [uy, vy]: line) {
        while (!pq.empty() && pq.top().first < idx[uy]) {
            auto [vi, ui] = pq.top(); pq.pop();
            st.incr(ui, vi);
            ans = max(ans, st.query() + int(pq.size()));
        }
        pq.emplace(idx[vy], idx[uy]);
        ans = max(ans, st.query() + int(pq.size()));
    }

    cout << ans << '\n';
}