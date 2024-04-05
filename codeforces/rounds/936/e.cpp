#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 2e5;
const int mod = 1e9 + 7;
 
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<ll> f(mx + 1), fi(mx + 1);
    f[0] = fi[0] = 1;
    auto inv = [](ll x) {
        ll ret = 1;
        for (int i = mod - 2; i; i /= 2) {
            if (i & 1) ret = ret * x % mod;
            x = x * x % mod;
        }
        return ret;
    };
    for (int i = 1; i <= mx; i++) {
        f[i] = f[i - 1] * i % mod;
        fi[i] = inv(f[i]);
    }
    auto cmb = [&](int n, int k) {
        return f[n] * fi[k] % mod * fi[n - k] % mod;
    };
 
    int t; cin >> t;
    while (t--) {
        int n, m1, m2; cin >> n >> m1 >> m2;
        vector<int> p(m1), s(m2);
        for (int &p: p) cin >> p;
        for (int &s: s) cin >> s;
 
        if (p.back() != s.front() || p.front() != 1 || s.back() != n) {
            cout << 0 << '\n';
            continue;
        }
 
        ll ans = cmb(n - 1, p.back() - 1);
        for (int i = p.size() - 2; i >= 0; i--) ans = ans * cmb(p[i + 1] - 2, p[i] - 1) % mod * f[p[i + 1] - 1 - p[i]] % mod;
        for (int i = 1; i < s.size(); i++) ans = ans * cmb(n - s[i - 1] - 1, n - s[i]) % mod * f[s[i] - 1 - s[i - 1]] % mod;
        cout << ans << '\n';
    }
}