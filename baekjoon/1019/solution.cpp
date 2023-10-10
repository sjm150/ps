#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt[10];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (ll x = 1; x <= n; x *= 10) {
        ll q = n / x;
        ll r = n % x;
        ll l = q / 10;
        ll d = q % 10;
        if (l) {
            if (d) cnt[0] += l * x;
            else cnt[0] += (l - 1) * x + r + 1;
        }
        for (int i = 1; i < 10; i++) {
            if (i < d) cnt[i] += (l + 1) * x;
            else if (i > d) cnt[i] += l * x;
            else cnt[i] += l * x + r + 1;
        }
    }
    for (ll c: cnt) cout << c << ' ';
    cout << '\n';
}