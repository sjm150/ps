#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (a <= b) {
            int ans = 0;
            for (; a < b; a++) {
                if (a % 2) ans += x;
                else ans += min(x, y);
            }
            cout << ans << '\n';
        } else {
            if (a % 2 && a - 1 == b) cout << y << '\n';
            else cout << -1 << '\n';
        }
    }
}