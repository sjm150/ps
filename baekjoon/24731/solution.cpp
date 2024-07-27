#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e6 + 3;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll k; cin >> k;
    auto exp = [&](ll x, ll e) {
        ll ret = 1;
        for (; e; e /= 2) {
            if (e & 1) ret = ret * x % mod;
            x = x * x % mod;
        }
        return ret;
    };
    ll t = exp(2, k - 1);
    cout << (2 * exp(3, mod - 2) * (t * t - 1) - t + 1) % mod << '\n';
}