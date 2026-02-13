#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int m, s, x1, x2;
    cin >> m >> s >> x1 >> x2;
    auto mi = [&](ll x) {
        ll ret = 1;
        for (int i = m - 2; i; i /= 2) {
            if (i % 2) ret = ret * x % m;
            x = x * x % m;
        }
        return ret;
    };
    ll a = (x2 - x1 + m) * mi(x1 - s + m) % m;
    ll c = ((x1 - a * s) % m + m) % m;
    cout << a << ' ' << c << '\n';
}