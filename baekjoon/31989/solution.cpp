#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n, m;
    cin >> n >> m;
    vector<ll> x(2 * n + 1);
    for (ll &x: x) cin >> x;
    int mn = n, mx = n;
    ll ans = 0;
    while (m--) {
        int p, w;
        cin >> p >> w;
        p--;
        mn = min(mn, p);
        mx = max(mx, p);
        ans += abs(x[p] - x[n]) * w;
    }
    cout << ans + 2 * (x[mx] - x[mn]) << '\n';
}