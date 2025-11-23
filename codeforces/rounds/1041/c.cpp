#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int &a: a) cin >> a;
        for (int &b: b) cin >> b;

        vector<pair<int, int>> lr(n);
        for (int i = 0; i < n; i++) lr[i] = {min(a[i], b[i]), max(a[i], b[i])};
        sort(lr.begin(), lr.end());

        int mn = 1e9;
        for (int i = 0; i < n - 1; i++) {
            auto [l, r] = lr[i];
            auto [nl, nr] = lr[i + 1];
            if (nl <= r) {
                mn = 0;
                break;
            }
            mn = min(mn, nl - r);
        }

        ll ans = mn * 2;
        for (auto [l, r]: lr) ans += r - l;
        cout << ans << '\n';
    }
}