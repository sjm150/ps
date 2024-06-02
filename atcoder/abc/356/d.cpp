#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n, m; cin >> n >> m;
    ll mx = 1;
    int mxb = 0;
    while (mx <= n) {
        mx <<= 1;
        mxb++;
    }

    vector<ll> cnt(mxb);
    for (ll i = mx >> 1, b = mxb - 1; b >= 0; i >>= 1, b--) {
        cnt[b] = n / i / 2 * i % mod;
        if (i & n) cnt[b] = (cnt[b] + n % i + 1) % mod;
    }

    ll ans = 0;
    for (ll i = 1, b = 0; b < mxb; i <<= 1, b++) {
        if (i & m) ans = (ans + cnt[b]) % mod;
    }
    cout << ans << '\n';
}