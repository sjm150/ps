#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;
        if (x > y) {
            swap(a, b);
            swap(x, y);
        }
        int ans = max(0, (k - a + x) / x);
        k -= ans * x;
        ans += max(0, (k - b + y) / y);
        cout << ans << '\n';
    }
}