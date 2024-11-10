#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll mx = 1e18;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n), d(n - 1);
        for (ll &a: a) cin >> a;
        if (n % 2) {
            ll ans = mx;
            for (int i = 0; i < n; i += 2) {
                ll cur = 1;
                for (int j = 0; j < i; j += 2) cur = max(cur, a[j + 1] - a[j]);
                for (int j = i + 1; j < n; j += 2) cur = max(cur, a[j + 1] - a[j]);
                ans = min(ans, cur);
            }
            cout << ans << '\n';
        } else {
            ll ans = 1;
            for (int i = 0; i < n; i += 2) ans = max(ans, a[i + 1] - a[i]);
            cout << ans << '\n';
        }
    }
}