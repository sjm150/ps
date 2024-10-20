#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int mx = 1024;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int den = 1, x = 1e4;
    for (int i = mod - 2; i; i /= 2) {
        if (i & 1) den = ll(den) * x % mod;
        x = ll(x) * x % mod;
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), p(n);
        for (int &a: a) cin >> a;
        for (int &p: p) {
            cin >> p;
            p = ll(p) * den % mod;
        }
        vector<int> prb(mx, 0);
        prb[0] = 1;
        for (int i = 0; i < n; i++) {
            vector<int> nprb(mx, 0);
            for (int j = 0; j < mx; j++) {
                nprb[a[i] ^ j] = (nprb[a[i] ^ j] + ll(prb[j]) * p[i]) % mod;
                nprb[j] = (nprb[j] + ll(prb[j]) * (1 + mod - p[i])) % mod;
            }
            swap(prb, nprb);
        }
        int ans = 0;
        for (int i = 1; i < mx; i++) ans = (ans + ll(i * i) * prb[i]) % mod;
        cout << ans << '\n';
    }
}