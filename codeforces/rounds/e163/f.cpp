#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector<int> asum(n + 1), bsum(n + 1);
    asum[0] = bsum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> asum[i];
        asum[i] += asum[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> bsum[i];
        bsum[i] += bsum[i - 1];
    }
    int m = bsum[n];

    ll bse = 1, b = (mod + 1) / 2;
    for (int i = m; i; i /= 2) {
        if (i & 1) bse = bse * b % mod;
        b = b * b % mod;
    }

    auto inv = [&](ll x) {
        ll ret = 1;
        for (int i = mod - 2; i; i /= 2) {
            if (i & 1) ret = ret * x % mod;
            x = x * x % mod;
        }
        return ret;
    };

    vector<int> csum(m + 1);
    ll comb = 1;
    csum[0] = 1;
    for (int i = 1; i <= m; i++) {
        comb = comb * (m + 1 - i) % mod * inv(i) % mod;
        csum[i] = (csum[i - 1] + comb) % mod;
    }

    while (q--) {
        int l, r; cin >> l >> r;
        int k = 2 * (asum[r] - asum[l - 1]) - asum[n] + bsum[r] - bsum[l - 1];
        if (k <= 0) cout << 0 << ' ';
        else cout << csum[min(m, k - 1)] * bse % mod << ' ';
    }
    cout << '\n';
}