#include <bits/stdc++.h>
using namespace std;

typedef struct Segtree {
    int n;
    vector<int> val;
    Segtree(int n): n(n) {
        val.resize(4 * n, -1);
    }

    int query(int ql, int qr, int l, int r, int node) {
        if (qr < l || r < ql) return -1;
        if (ql <= l && r <= qr) return val[node];
        int m = (l + r) / 2;
        int lval = query(ql, qr, l, m, 2 * node + 1);
        int rval = query(ql, qr, m + 1, r, 2 * node + 2);
        return max(lval, rval);
    }
    int query(int l, int r) {
        if (l > r) return -1;
        return query(l, r, 0, n - 1, 0);
    }

    int update(int i, int v, int l, int r, int node) {
        if (i < l || r < i) return val[node];
        if (l == r) return val[node] = v;
        int m = (l + r) / 2;
        int lval = update(i, v, l, m, 2 * node + 1);
        int rval = update(i, v, m + 1, r, 2 * node + 2);
        return val[node] = max(lval, rval);
    }
    void update(int i, int v) {
        update(i, v, 0, n - 1, 0);
    }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string s, t; cin >> s >> t;

        queue<int> q[26];
        for (int i = 0; i < n; i++) q[s[i] - 'a'].push(i);
        Segtree st(26);
        bool poss = true;
        for (char c: t) {
            int idx = c - 'a';
            int lim = st.query(idx + 1, 26);
            while (!q[idx].empty() && q[idx].front() <= lim) q[idx].pop();
            if (q[idx].empty()) {
                poss = false;
                break;
            }
            st.update(idx, q[idx].front());
            q[idx].pop();
        }

        if (poss) cout << "YES\n";
        else cout << "NO\n";
    }
}