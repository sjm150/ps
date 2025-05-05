#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        if (n == 1 && x == 0) {
            cout << -1 << '\n';
            continue;
        }
        int r = n;
        for (int i = x; i; i /= 2) {
            if (i & 1) r--;
        }
        if (r < 0) r = 0;
        if (r & 1) r++;
        ll ans = x;
        if (r > (n - (x & 1))) {
            ans += r - 2;
            r = 2;
        } else {
            ans += r;
            r = 0;
        }
        ans += r * 2;
        cout << ans << '\n';
    }
}