#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n, m;
    ll a;
    cin >> n >> m >> a;
    if (n > m) swap(n, m);

    auto solve = [&]() {
        if (a % n == 0 || a % m == 0) return 1;

        for (ll i = 1; i * i <= a; i++) {
            if (a % i) continue;
            if (i <= n && a / i <= m) return 2;
        }
        ll b = ll(n) * m - a;
        for (ll i = 1; i * i <= b; i++) {
            if (b % i) continue;
            if (i <= n && b / i <= m) return 2;
        }

        return 3;
    };

    cout << solve() << '\n';
}