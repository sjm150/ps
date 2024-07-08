#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m; cin >> m;
    vector<int> f(2 * m + 1);
    f[0] = 1;
    for (int i = 1; i <= 2 * m; i++) f[i] = ll(f[i - 1]) * i % mod;
    vector<int> inv(m + 1), fi(m + 1);
    inv[0] = inv[1] = fi[0] = fi[1] = 1;
    for (int i = 2; i <= m; i++) {
        inv[i] = (mod - ll(mod / i) * inv[mod % i] % mod) % mod;
        fi[i] = ll(fi[i - 1]) * inv[i] % mod;
    }
    int ans = 0;
    for (int i = 3; i <= m; i++) ans = (ans + ll(f[2 * i]) * fi[i] % mod * fi[i]) % mod;
    cout << ans << '\n';
}