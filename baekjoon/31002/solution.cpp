#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll mod = 1e9 + 7;
    ll n, k;
    cin >> n >> k;
    ll e = n - 1;
    while (k--) {
        n = n * e % mod * ((mod + 1) / 2) % mod;
        e = (e - 1) * 2 % mod;
    }
    cout << n << '\n';
}