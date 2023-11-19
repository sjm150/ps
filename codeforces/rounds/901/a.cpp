#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, n; cin >> a >> b >> n;
        ll ans = b;
        while (n--) {
            int x; cin >> x;
            ans += min(a - 1, x);
        }
        cout << ans << '\n';
    }
}