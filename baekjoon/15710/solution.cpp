#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mod = 1e9 + 7;
    int a, b, n;
    cin >> a >> b >> n;
    ll x = 2, ans = 1;
    for (ll i = 31 * ll(n - 1); i; i /= 2) {
        if (i % 2) ans = ans * x % mod;
        x = x * x % mod;
    }
    cout << ans << '\n';
}