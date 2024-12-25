#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll x = 1;
        for (; n; n /= 4) x *= 2;
        cout << x / 2 << '\n';
    }
}