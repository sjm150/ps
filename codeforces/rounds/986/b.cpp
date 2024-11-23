#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        ll n, b, c; cin >> n >> b >> c;
        if (b) {
            if (c < n) cout << n - min(n, (n - 1 - c) / b + 1) << '\n';
            else cout << n << '\n';
        } else {
            if (c < n) cout << (c < n - 2 ? -1 : n - 1) << '\n';
            else cout << n << '\n';
        }
    }
}