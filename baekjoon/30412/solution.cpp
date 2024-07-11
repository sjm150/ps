#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    ll ans = min(max(0, x - abs(a[0] - a[1])), max(0, x - abs(a[n - 2] - a[n - 1])));
    for (int i = 1; i < n - 1; i++) {
        ll mn = min(a[i - 1], a[i + 1]), mx = max(a[i - 1], a[i + 1]);
        ans = min(ans, max(0ll, a[i] + x - mn) + max(0ll, a[i] + x - mx));
        ans = min(ans, max(0ll, mx + x - a[i]));
        ll t = max(mn + x, ll(a[i]));
        ans = min(ans, max(0ll, t - a[i]) + max(0ll, t + x - mx));
    }

    cout << ans << '\n';
}