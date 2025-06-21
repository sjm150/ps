#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mod = 1e9 + 7;
    auto inv = [&](ll x) {
        ll ret = 1;
        for (int i = mod - 2; i; i /= 2) {
            if (i % 2) ret = ret * x % mod;
            x = x * x % mod;
        }
        return ret;
    };
    int t; cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;
        ll n = ll(a - 1) * k + 1;
        ll m = ll(b - 1) * k % mod;
        if (n > a) {
            for (int i = 1; i <= a; i++) m = (n + 1 - i) % mod * m % mod * inv(i) % mod;
        }
        n %= mod;
        m = (m + 1) % mod;
        cout << n << ' ' << m << '\n';
    }
}