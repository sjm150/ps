#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &a: a) cin >> a;

    auto s = a;
    sort(s.begin(), s.end());

    function<ll(ll, ll)> gcd = [&](ll a, ll b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    auto chk = [](ll x) {
        ll s = sqrt(x);
        for (int i = s - 1; i <= s + 1; i++) {
            if (s * s == x) return true;
        }
        return false;
    };

    bool ok = true;
    for (int i = 0; i < n; i++) {
        ll g = gcd(a[i], s[i]);
        if (!chk(a[i] / g) || !chk(s[i] / g)) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}