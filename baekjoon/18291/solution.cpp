#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 1e9 + 7;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long ans = 1, cur = 2;
        for (n -= 2; n > 0; n /= 2) {
            if (n % 2) ans = ans * cur % mod;
            cur = cur * cur % mod;
        }
        cout << ans << '\n';
    }
}