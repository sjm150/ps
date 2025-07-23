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
        ll a, b, k;
        cin >> a >> b >> k;
        ll g = gcd(a, b);
        cout << (a / g <= k && b / g <= k ? 1 : 2) << '\n';
    }
}