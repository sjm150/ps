#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mod = 1e9 + 7;

    ll n, m; cin >> n >> m;
    int k; cin >> k;
    vector<ll> a(k), b(k);
    for (int i = 0; i < k; i++) cin >> a[i] >> b[i];

    if (n == 1) {
        cout << (m == 1) << '\n';
        return 0;
    }

    ll ans = 1;
    for (ll x = n - 1, e = (a[0] - 1 + m - a[k - 1]) % (mod - 1); e; e /= 2) {
        if (e % 2) ans = ans * x % mod;
        x = x * x % mod;
    }

    typedef array<array<ll, 2>, 2> mat;
    mat zr = {array<ll, 2>{0, 0}, {0, 0}};
    mat id = {array<ll, 2>{1, 0}, {0, 1}};
    mat bs = {array<ll, 2>{n - 2, n - 1}, {1, 0}};
    auto mul = [&](const mat &a, const mat &b) {
        mat r = zr;
        for (int i = 0; i < 2; i++) {
            for (int k = 0; k < 2; k++) {
                for (int j = 0; j < 2; j++) {
                    r[i][j] = (r[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return r;
    };

    for (int i = 0; i < k - 1; i++) {
        mat r = id, x = bs;
        for (ll e = a[i + 1] - a[i] - 1; e; e /= 2) {
            if (e % 2) r = mul(r, x);
            x = mul(x, x);
        }
        ans = ans * r[0][b[i] == b[i + 1]] % mod;
    }

    cout << ans << '\n';
}