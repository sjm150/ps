#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    ll k; cin >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    ll ans = k;
    for (int i = 1; i < n; i++) {
        ll t = ll(v[0]) * i + ll(n - i) * v[i];
        ans = min(ans, (k + t - 1) / t);
    }
    cout << ans << '\n';
}