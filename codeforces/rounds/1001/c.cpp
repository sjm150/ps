#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (ll &a: a) cin >> a;
        ll ans = accumulate(a.begin(), a.end(), 0ll);
        while (a.size() > 1) {
            int sz = a.size();
            vector<ll> na(sz - 1);
            for (int i = 0; i < sz - 1; i++) na[i] = a[i + 1] - a[i];
            swap(a, na);
            ans = max(ans, abs(accumulate(a.begin(), a.end(), 0ll)));
        }
        cout << ans << '\n';
    }
}