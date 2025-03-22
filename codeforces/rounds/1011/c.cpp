#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        if (x == y) {
            cout << -1 << '\n';
            continue;
        }
        ll k = 0, ld = 0;
        auto add = [&](ll v) {
            k += v;
            x += v;
            y += v;
        };
        for (ll b = 1; b <= max(x, y); b <<= 1) {
            if ((x & b) && (y & b)) {
                if (ld) {
                    add(b - ld);
                    ld = b;
                } else {
                    add(b);
                }
            } else if ((x & b) || (y & b)) {
                ld = b;
            }
        }
        cout << k << '\n';
    }
}