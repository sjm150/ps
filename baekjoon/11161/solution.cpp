#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int m; cin >> m;
        int ans = 0, cur = 0;
        while (m--) {
            int p, q; cin >> p >> q;
            cur += p - q;
            ans = max(ans, -cur);
        }
        cout << ans << '\n';
    }
}