#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll l = 0, r = ll(1e9);
        while (l < r) {
            ll m = (l + r) / 2;
            ll cnt = m * (3 * m + 1) / 2;
            if (cnt < n) l = m + 1;
            else r = m;
        }
        r--;
        ll base = 3 * r * ((3 * r) + 1) / 2;
        ll rem = n - base / 3 - 1;
        ll cur = base + 1;
        while (rem--) cur += 3;
        if (cur >= base + 6 * r + 2) cur++;
        cout << cur << '\n';
    }
}