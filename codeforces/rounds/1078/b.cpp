#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        ll ans = 0, sum = 0;
        for (int a: a) sum += a / x * y;
        for (int a: a) ans = max(ans, a + sum - a / x * y);
        cout << ans << '\n';
    }
}