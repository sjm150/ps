#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mx = 1e6;
const int mod = 998244353;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<int> f(mx + 1), fi(mx + 1);
    f[0] = fi[0] = f[1] = fi[1] = 1;
    for (int i = 2; i <= mx; i++) f[i] = ll(f[i - 1]) * i % mod;
    for (int i = 2; i <= mx; i++) fi[i] = ll(mod - mod / i) * fi[mod % i] % mod;
    for (int i = 2; i <= mx; i++) fi[i] = ll(fi[i]) * fi[i - 1] % mod;

    auto cmb = [&](int n, int k) {
        return ll(f[n]) * fi[k] % mod * fi[n - k] % mod;
    };

    int t; cin >> t;
    while (t--) {
        int l, n; cin >> l >> n;
        int cnt = 0;
        for (int i = 0; i <= l / 2 - n; i++) {
            cnt = (cnt + cmb(i + n - 1, n - 1) * cmb(l - n - 2 * i, n)) % mod;
        }
        cout << (cmb(l, 2 * n) + mod - cnt) * 2 % mod << '\n';
    }
}