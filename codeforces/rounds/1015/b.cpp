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
        int n; cin >> n;
        vector<ll> a(n);
        for (ll &a: a) cin >> a;
        sort(a.begin(), a.end());
        ll g = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] % a[0] == 0) g = gcd(a[i], g);
        }
        cout << (a[0] == g ? "YES\n" : "NO\n");
    }
}