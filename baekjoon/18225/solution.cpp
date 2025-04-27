#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int a, b, x, y, p, q;
    cin >> a >> b >> x >> y >> p >> q;

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

    auto solve = [&]() {
        ll t0 = calc(p, x, a);
        if (t0 < 0) return ll(-1);

        ll ag = a / gcd(a, p);
        ll t1 = calc(ag * q, t0 * q + y, b);
        if (t1 < 0) return ll(-1);

        ll t = t0 + ag * t1, i = (p * t + x) / a, j = (q * t + y) / b;
        return (i > 0 ? i - 1 : -i) + (j > 0 ? j - 1: -j) + 1;
    };
    cout << solve() << '\n';
}