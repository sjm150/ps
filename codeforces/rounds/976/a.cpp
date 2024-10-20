#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (k == 1) {
            cout << n << '\n';
            continue;
        }
        int ans = 0;
        for (; n; n /= k) ans += n % k;
        cout << ans << '\n';
    }
}