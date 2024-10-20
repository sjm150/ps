#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mx = 1e18;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll b, c, d; cin >> b >> c >> d;
        ll ans = 0;
        for (ll i = 1; i <= mx; i *= 2) {
            if ((b & i) && (c & i)) {
                if (!(d & i)) ans |= i;
            } else if (!(b & i) && (c & i)) {
                if (d & i) {
                    ans = -1;
                    break;
                }
            } else if ((b & i) && !(c & i)) {
                if (!(d & i)) {
                    ans = -1;
                    break;
                }
            } else {
                if (d & i) ans |= i;
            }
        }
        cout << ans << '\n';
    }
}