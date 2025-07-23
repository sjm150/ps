#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        auto cnt = [&](ll p) { return r / p - (l - 1) / p; };
        const int ps[] = {2, 3, 5, 7};
        ll ans = r - l + 1;
        for (int i = 1; i < 16; i++) {
            int c = 0, p = 1;
            for (int j = 0; j < 4; j++) {
                if ((i >> j) & 1) {
                    c++;
                    p *= ps[j];
                }
            }
            ans += (c % 2 ? -1 : 1) * cnt(p);
        }
        cout << ans << '\n';
    }
}