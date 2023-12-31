#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;

int f[53], fi[53];

int modinv(int x) {
    int ret = 1, b = x;
    for (int i = mod - 2; i; i >>= 1) {
        if (i & 1) ret = ret * b % mod;
        b = b * b % mod;
    }
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    f[0] = fi[0] = 1;
    for (int i = 1; i < 53; i++) {
        f[i] = f[i - 1] * i % mod;
        fi[i] = modinv(f[i]);
    }

    int n; cin >> n;
    int ans = 0;
    int q = n / 4;
    for (int i = 1; i <= q; i++) {
        int t = f[13] * fi[i] % mod * fi[13 - i] % mod
            * f[52 - 4 * i] % mod * fi[n - 4 * i] % mod * fi[52 - n] % mod;
        if (i & 1) ans = (ans + t) % mod;
        else ans = (ans - t) % mod;
    }

    cout << (ans + mod) % mod << '\n';
}