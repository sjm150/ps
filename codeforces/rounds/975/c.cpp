#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll k; cin >> k;
        vector<ll> a(n);
        for (ll &a: a) cin >> a;
        ll sum = accumulate(a.begin(), a.end(), 0ll);
        ll mx = *max_element(a.begin(), a.end());
        ll ans = min(ll(n), (sum + k) / mx);
        while ((sum + k) / ans * ans < sum) ans--;
        cout << ans << '\n';
    }
}