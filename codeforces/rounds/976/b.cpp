#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll k; cin >> k;
        ll l = k, r = 2e18;
        while (l < r) {
            ll m = (l + r) / 2;
            ll sl = 1, sr = sqrt(m) + 10;
            while (sl < sr) {
                ll sm = (sl + sr) / 2;
                if (sm * sm <= m) sl = sm + 1;
                else sr = sm;
            }
            if (m - sr + 1 < k) l = m + 1;
            else r = m;
        }
        cout << r << '\n';
    }
}