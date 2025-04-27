#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    function<ll(ll, ll)> gcd = [&](ll a, ll b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    function<ll(ll, ll)> inv = [&](ll a, ll b) {
        if (a == 1) return 1ll;
        return b - inv(b % a, a) * b / a;
    };
    auto calc = [&](ll p, ll q, int mod) {
        ll g = gcd(p, mod);
        if (q % g) return ll(-1);
        p /= g;
        q /= g;
        mod /= g;
        return (-q % mod + mod) * inv(p, mod) % mod;
    };
    int t; cin >> t;
    while (t--) {
        int n, x, y, vx, vy;
        cin >> n >> x >> y >> vx >> vy;
        ll g = gcd(vx, vy);
        vx /= g;
        vy /= g;

        auto solve = [&]() {
            ll t0 = calc(vx, x, n);
            if (t0 < 0) return ll(-1);

            ll coef = n / gcd(n, vx);
            ll t1 = calc(coef * vy, t0 * vy + y, n);
            if (t1 < 0) return ll(-1);

            ll t = t0 + coef * t1, i = (vx * t + x) / n, j = (vy * t + y) / n;
            return i - 1 + j - 1 + (i + j) / 2 + abs(i - j) / 2;
        };
        cout << solve() << '\n';
    }
}