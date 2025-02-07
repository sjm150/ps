#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const double mx = 1e5, eps = 1e-7;
    int s; cin >> s;
    double l = 0, r = mx;
    while (r - l > eps) {
        double m = (l + r) / 2;
        ll cnt = 0;
        for (int i = 1; i < m; i++) {
            ll x = sqrt(m * m - i * i);
            if ((x + 1) * (x + 1) + i * i <= m * m) x++;
            cnt += 4 * x;
        }
        if (cnt <= s) l = m;
        else r = m;
    }
    cout << setprecision(7) << l << '\n';
}