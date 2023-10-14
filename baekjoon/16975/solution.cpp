#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct FwTree {
    vector<ll> val;
    FwTree(int n) {
        val = vector<ll>(n + 2);
    }
    void add(int idx, int x) {
        while (idx < val.size()) {
            val[idx] += x;
            idx += idx & -idx;
        }
    }
    ll get(int idx) {
        ll v = 0;
        while (idx) {
            v += val[idx];
            idx &= idx - 1;
        }
        return v;
    }
} fwt_t;

int a[100001];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    fwt_t fwt(n);
    int m; cin >> m;
    while (m--) {
        int q; cin >> q;
        if (q == 1) {
            int i, j, k; cin >> i >> j >> k;
            fwt.add(i, k);
            fwt.add(j + 1, -k);
        } else if (q == 2) {
            int x; cin >> x;
            cout << a[x] + fwt.get(x) << '\n';
        }
    }
}