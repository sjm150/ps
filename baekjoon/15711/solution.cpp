#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mx = 1414215;
    vector<bool> isp(mx, true);
    vector<int> p;
    for (ll i = 2; i < mx; i++) {
        if (!isp[i]) continue;
        p.push_back(i);
        for (ll j = i * i; j < mx; j += i) isp[j] = false;
    }
    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        a += b;
        if (a % 2) {
            a -= 2;
            bool ok = true;
            if (a == 1) ok = false;
            for (int p: p) {
                if (ll(p) * p > a) break;
                if (a % p == 0) {
                    ok = false;
                    break;
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        } else {
            if (a > 2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}