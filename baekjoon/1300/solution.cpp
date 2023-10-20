#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool poss(ll x, int n) {
    for (ll i = 1; i * i <= x; i++) {
        if (i > n) break;
        if (x % i == 0 && x / i <= n) return true;
    }
    return false;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    ll l = 0, r = ll(n) * n + 1;
    while (l < r) {
        ll m = (l + r) / 2;
        ll cnt = 0;
        for (ll i = 1; i * i <= m - 1; i++) {
            if (i > n) break;
            ll q = min(ll(n), (m - 1) / i);
            cnt += 2 * q - 2 * i + 1;
        }
        if (cnt <= k - 1) l = m + 1;
        else r = m;
    }
    r--;
    while (!poss(r, n)) r++;
    cout << r << '\n';
}