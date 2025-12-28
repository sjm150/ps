#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    ll s, x;
    cin >> s >> x;
    ll cnt = 1, d = s - x;
    for (ll i = x; i; i /= 2) {
        if (i % 2) cnt *= 2;
    }
    if (d == 0) cout << cnt - 2 << '\n';
    else if (d < 0 || d % 2 || ((d / 2) & x)) cout << 0 << '\n';
    else cout << cnt << '\n';
}