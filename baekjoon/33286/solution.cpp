#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll mod = 1e9 + 7;
    ll n, k;
    cin >> n >> k;
    auto sqr = [](ll x) { return x * x % mod; };
    if (n % 2) {
        cout << sqr(k % mod) << '\n';
    } else {
        ll ans = 0;
        for (ll i = 1; i * i <= k; i++) {
            ans = (ans + sqr(k / i % mod)) % mod;
            if (i * i != k) ans = (ans + (k / i - max(k / (i + 1), i)) % mod * sqr(i)) % mod;
        }
        cout << ans << '\n';
    }
}