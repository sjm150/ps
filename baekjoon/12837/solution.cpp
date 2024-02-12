#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Fwtree {
    vector<ll> val;
    Fwtree(int n) { val.resize(n + 1, 0); }

    void add(int x, int v) {
        while (x < val.size()) {
            val[x] += v;
            x += x & -x;
        }
    }

    ll get(int x) {
        ll ret = 0;
        while (x) {
            ret += val[x];
            x &= x - 1;
        }
        return ret;
    }
} fwt_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    fwt_t fwt(n);
    while (q--) {
        int c, p, x; cin >> c >> p >> x;
        if (c == 1) fwt.add(p, x);
        else cout << fwt.get(x) - fwt.get(p - 1) << '\n';
    }
}