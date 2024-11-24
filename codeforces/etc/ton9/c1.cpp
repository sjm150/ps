#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        ll m; cin >> m;
        int mx = 1, ans = 0;
        while (mx <= x) mx *= 2;
        if (mx > m) mx = m + 1;
        for (int y = 1; y < mx; y++) {
            if (x == y) continue;
            int r = x ^ y;
            if (x % r == 0 || y % r == 0) ans++;
        }
        cout << ans << '\n';
    }
}