#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mod = 998244353;
    const int mx = 2e5 + 1;

    vector<int> f(mx), fi(mx), ex2(mx);
    f[0] = fi[0] = f[1] = fi[1] = ex2[0] = 1;
    ex2[1] = 2;
    for (int i = 2; i < mx; i++) {
        f[i] = ll(f[i - 1]) * i % mod;
        ll inv = 1, x = i;
        for (int e = mod - 2; e; e /= 2) {
            if (e % 2) inv = inv * x % mod;
            x = x * x % mod;
        }
        fi[i] = fi[i - 1] * inv % mod;
        ex2[i] = ex2[i - 1] * 2 % mod;
    }
    auto comb = [&](int n, int k) { return ll(f[n]) * fi[k] % mod * fi[n - k] % mod; };

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> cnt(n, 0), bgc(n);
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            cnt[a]++;
        }
        bgc[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) bgc[i] = (bgc[i + 1] + cnt[i + 1]) % mod;

        int ans = 0;
        vector<ll> k(cnt[0] + 1);
        for (int i = 0; i <= cnt[0]; i++) {
            k[i] = comb(cnt[0], i);
            ans = (ans + ll(k[i]) * i) % mod;
        }
        ans = ll(ans) * ex2[bgc[0]] % mod;

        for (int x = 1; x < n; x++) {
            vector<ll> bge(cnt[x - 1] + 2);
            bge[cnt[x - 1] + 1] = 0;
            for (int i = cnt[x - 1]; i >= 0; i--) bge[i] = (bge[i + 1] + k[i]) % mod;

            vector<ll> nk(cnt[x] + 1);
            ll aph = 0;
            for (int i = cnt[x]; i >= 0; i--) {
                ll c = comb(cnt[x], i);
                nk[i] = (bge[min(ll(i), cnt[x - 1] + 1)] * c + aph * (i <= cnt[x - 1] ? k[i] : 0)) % mod;
                aph = (aph + c) % mod;
            }
            swap(k, nk);

            for (int i = 0; i <= cnt[x]; i++) ans = (ans + ll(k[i]) * i % mod * ex2[bgc[x]]) % mod;
        }
        cout << ans << '\n';
    }
}