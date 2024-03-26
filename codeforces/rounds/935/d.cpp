#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(n);
        for (int &a: a) cin >> a;
        for (int &b: b) cin >> b;

        ll sum = 0;
        for (int i = n - 1; i >= m; i--) sum += min(a[i], b[i]);
        ll ans = 1e18;
        for (int i = m - 1; i >= 0; i--) {
            ans = min(ans, a[i] + sum);
            sum += min(a[i], b[i]);
        }

        cout << ans << '\n';
    }
}