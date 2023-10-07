#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        ll a, b, c; cin >> a >> b >> c;
        ll ans = 0;
        if (2 * a <= b) {
            ans = c / a;
        } else {
            ans = max(ans, c / b * 2 - 1);
            for (int i = 1; i <= 2; i++) {
                if (c >= i * a) ans = max(ans, (c - i * a) / b * 2 + i);
            }
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }
}