#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e18;
typedef struct Tree {
    typedef struct Node {
        ll sz = 0;
        char c = 0;
        int l, r;
        Node() {};
        Node(int l, int r, ll sz): l(l), r(r), sz(min(inf, sz)) {}
    } nd_t;
    vector<nd_t> nds;
    vector<int> lf;
    Tree(): nds(26), lf(26) {
        for (int i = 0; i < 26; i++) {
            nds[i].sz = 1;
            nds[i].c = i + 'a';
            lf[i] = i;
        }
    }

    int nnd(string &s, int l, int r) {
        if (l == r) return lf[s[l] - 'a'];
        int m = (l + r) / 2;
        int nl = nnd(s, l, m), nr = nnd(s, m + 1, r);
        nds.emplace_back(nl, nr, nds[nl].sz + nds[nr].sz);
        return nds.size() - 1;
    }
    void replace(char c, string &s) { lf[c - 'a'] = nnd(s, 0, s.size() - 1); }

    void prnt(ll l, ll r, int cur) {
        if (l >= nds[cur].sz || r < 0) return;
        l = max(l, 0ll);
        r = min(r, nds[cur].sz - 1);
        if (nds[cur].c) {
            cout << nds[cur].c;
        } else {
            ll sz = nds[nds[cur].l].sz;
            prnt(l, r, nds[cur].l);
            prnt(l - sz, r - sz, nds[cur].r);
        }
    }
    void prnt(ll l, ll r) {
        prnt(l, r, lf[0]);
        cout << '\n';
    }
} tr_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll l, r; cin >> l >> r;
    int n; cin >> n;
    vector<pair<char, string>> op(n);
    for (auto &[c, s]: op) cin >> c >> s;
    tr_t tr;
    for (int i = n - 1; i >= 0; i--) tr.replace(op[i].first, op[i].second);
    tr.prnt(l - 1, r - 1);
}