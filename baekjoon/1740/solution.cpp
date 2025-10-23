#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; n; n /= 2, i *= 3) {
        if (n % 2) ans += i;
    }
    cout << ans << '\n';
}