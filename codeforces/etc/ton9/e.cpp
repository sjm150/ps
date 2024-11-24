#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mod = 998244353;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 2) {
            cout << 1 << '\n';
            continue;
        }
        if (n == 3) {
            cout << 2 << '\n';
            continue;
        }
        ll cnt = 0, bse = 2, bwc = 2;
        for (int i = 4; i <= n; i++) {
            ll pre = cnt;
            cnt = (pre * (i - 1) + bwc) % mod;
            bse = (pre + bse + 1) % mod;
            bwc = (pre * (i - 1) + bwc + i - 1) % mod;
        }
        cout << (cnt + bse) % mod << '\n';
    }
}