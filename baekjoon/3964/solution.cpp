#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll inf = 1e18;
    const int mx = 1e6;
    vector<bool> isp(mx, true);
    vector<ll> p;
    for (ll i = 2; i < mx; i++) {
        if (!isp[i]) continue;
        p.push_back(i);
        for (ll j = i * i; j < mx; j += i) isp[j] = false;
    }
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        ll kk = k, ans = inf;
        for (ll p: p) {
            if (p * p > k) break;
            ll kc = 0;
            for (; kk % p == 0; kk /= p) kc++;
            if (kc == 0) continue;
            ll nc = 0;
            for (ll i = n / p; i; i /= p) nc += i;
            ans = min(ans, nc / kc);
        }
        if (kk > 1) {
            ll nc = 0;
            for (ll i = n / kk; i; i /= kk) nc += i;
            ans = min(ans, nc);
        }
        cout << (ans < inf ? ans : 0) << '\n';
    }
}