#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        ll m; cin >> m;
        ll ans = 0;
        int mx = 1;
        while (mx <= x) mx *= 2;
        if (mx > m) mx = m + 1;
        for (int y = 1; y < mx; y++) {
            int r = x ^ y;
            if (r % x == 0 || r % y == 0) ans++;
        }
        ll cur = m / x * x - 2 * x;
        if (cur / x - (mx - 1) / x > 0) ans += cur / x - (mx - 1) / x;
        for (cur = m / x * x - x; cur <= m / x * x + 2 * x; cur += x) {
            ll y = cur ^ x;
            if (y >= mx && y <= m) ans++;
        }
        cout << ans << '\n';
    }
}