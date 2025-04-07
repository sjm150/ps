#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    ll d, p, q; cin >> d >> p >> q;
    if (p < q) swap(p, q);
    ll ans = d + q;
    for (int i = 0; i < q; i++) {
        if (i * p >= d + q) break;
        ans = min(ans, (q - (d - i * p) % q) % q + d);
    }
    cout << ans << '\n';
}