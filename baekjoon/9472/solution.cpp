#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t;
    cin >> t;
    while (t--) {
        int tc, n, k;
        cin >> tc >> n >> k;
        ll f = 1, c = 1;
        for (int i = 1; i <= n; i++) f *= i;
        ll ans = f;
        for (int i = 1; i <= k; i++) {
            f /= n + 1 - i;
            c = c * (k + 1 - i) / i;
            ans += f * c * (i % 2 ? -1 : 1);
        }
        cout << tc << ' ' << ans << '\n';
    }
}