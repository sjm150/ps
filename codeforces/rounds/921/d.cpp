#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

ll exp(ll x, int e) {
    ll ret = 1;
    for (; e; e >>= 1) {
        if (e & 1) ret = ret * x % mod;
        x = x * x % mod;
    }
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        ll fsum = 0;
        for (int i = 0; i < m; i++) {
            int a, b, f; cin >> a >> b >> f;
            fsum = (fsum + f) % mod;
        }

        ll pcnt = ll(n) * (n - 1) / 2 % mod;
        ll per = exp(pcnt, mod - 2);
        ll ans = 0;
        while (k--) {
            ans = (ans + fsum * per) % mod;
            fsum = (fsum + m * per) % mod;
        }

        cout << ans << '\n';
    }
}