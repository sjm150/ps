#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    function<ll(ll, ll)> gcd = [&](ll a, ll b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    int t; cin >> t;
    while (t--) {
        ll l, r, g; cin >> l >> r >> g;
        l = (l + g - 1) / g;
        r = r / g;
        bool prnt = false;
        for (ll len = r - l + 1; len; len--) {
            for (ll i = l; i + len - 1 <= r; i++) {
                if (gcd(i, i + len - 1) == 1) {
                    cout << i * g << ' ' << (i + len - 1) * g << '\n';
                    prnt = true;
                    break;
                }
            }
            if (prnt) break;
        }
        if (!prnt) cout << -1 << ' ' << -1 << '\n';
    }
}