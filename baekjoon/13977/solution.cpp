#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int mx = 4e6;

ll power(ll base, int exp) {
    ll res = 1;
    while (exp) {
        if (exp % 2) res = res * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<ll> fact(mx + 1), factinv(mx + 1);
    fact[0] = factinv[0] = 1;
    for (int i = 1; i <= mx; i++) {
        fact[i] = fact[i - 1] * i % mod;
        factinv[i] = factinv[i - 1] * power(i, mod - 2) % mod;
    }

    int m; cin >> m;
    while (m--) {
        int n, k; cin >> n >> k;
        cout << fact[n] * factinv[k] % mod * factinv[n - k] % mod << '\n';
    }
}