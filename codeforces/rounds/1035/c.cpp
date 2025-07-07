#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        ll n, l, r, k;
        cin >> n >> l >> r >> k;
        if (n % 2) {
            cout << l << '\n';
        } else if (n > 2) {
            ll x = 1;
            while (x <= l) x *= 2;
            if (x > r) {
                cout << -1 << '\n';
            } else {
                if (k >= n - 1) cout << x << '\n';
                else cout << l << '\n';
            }
        } else {
            cout << -1 << '\n';
        }
    }
}