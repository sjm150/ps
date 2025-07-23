#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mod = 998244353;
    auto inv = [&](ll x) {
        ll ret = 1;
        for (int i = mod - 2; i; i /= 2) {
            if (i % 2) ret = ret * x % mod;
            x = x * x % mod;
        }
        return ret;
    };

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int, int>> seg(n);
    for (auto &[l, r, p, q]: seg) cin >> l >> r >> p >> q;
    sort(seg.begin(), seg.end());

    vector<ll> prb(m + 1, 0);
    prb[0] = 1;
    for (auto [l, r, p, q]: seg) prb[0] = prb[0] * (q - p) % mod * inv(q) % mod;
    for (auto [l, r, p, q]: seg) prb[r] = (prb[r] + prb[l - 1] * p % mod * inv(q - p)) % mod;

    cout << prb[m] << '\n';
}