#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    typedef pair<ll, ll> pl;
    function<ll(ll, ll)> gcd = [&](ll a, ll b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    auto add = [&](const pl &a, const pl &b) {
        ll g = gcd(a.second, b.second);
        pl ret = pl(b.second / g * a.first + a.second / g * b.first, a.second / g * b.second);
        g = gcd(ret.first, ret.second);
        ret.first /= g;
        ret.second /= g;
        return ret;
    };
    auto mul = [&](const pl &a, const pl &b) {
        pl ret = pl(a.first * b.first, a.second * b.second);
        ll g = gcd(ret.first, ret.second);
        ret.first /= g;
        ret.second /= g;
        return ret;
    };
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        pl ans = {0, 1}, cur = {1, 1};
        for (; m >= 0; m -= 2) {
            ans = add(ans, mul(cur, pl(n, n + m)));
            if (m > 1) cur = mul(cur, mul(pl(m, n + m), pl(m - 1, n + m - 1)));
        }
        cout << ans.first << '/' << ans.second << '\n';
    }
}