#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mx = 1e6;
    const ll mod = ll(1e18) + 31;
    vector<ll> a(mx + 1, 1);
    a[mx] = 300;
    for (int i = mx - 1; i >= 0; i--) {
        __int128_t x = 42;
        for (ll j = a[i + 1]; j; j /= 2) {
            if (j % 2) a[i] = a[i] * x % mod;
            x = x * x % mod;
        }
    }
    int n;
    cin >> n;
    cout << a[n] << '\n';
}