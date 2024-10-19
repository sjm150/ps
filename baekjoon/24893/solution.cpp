#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n, a, b, e; cin >> n >> a >> b >> e;
    vector<ll> sum(n + 1);
    sum[0] = -e;
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    ll ans = a * max(0ll, sum[n] + 1) - b * ll(1e9);
    for (int t = 1; t <= n; t++) {
        ll k = sum[n] / ((n + t - 1) / t) + 1;
        for (int i = 1; i * t < n; i++) k = max(k, sum[i * t] / i + 1);
        ans = min(ans, a * k - b * t);
    }
    cout << ans << '\n';
}