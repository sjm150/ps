#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    ll k, a, b;
    cin >> k >> a >> b;
    if (k == 0) {
        cout << b - a + 1 << '\n';
        return 0;
    }
    ll l = k, r = k;
    if (r % 2 == 0) r++;
    ll ans = 0;
    while (r < a) l *= 2, r = r * 2 + 1;
    while (l <= b) {
        ans += min(r, b) - max(l, a) + 1;
        l *= 2, r = r * 2 + 1;
    }
    cout << ans << '\n';
}