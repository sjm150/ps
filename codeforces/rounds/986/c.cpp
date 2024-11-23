#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n, m, v; cin >> n >> m >> v;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        vector<ll> l(m + 1, -1), r(m + 1, -1);
        l[0] = r[0] = 0;
        ll cur = 0;
        int idx = 1;
        for (int i = 0; idx <= m && i < n; i++) {
            cur += a[i];
            if (cur >= v) {
                l[idx] = l[idx - 1] + cur;
                cur = 0;
                idx++;
            }
        }
        cur = 0, idx = 1;
        for (int i = n - 1; idx <= m && i >= 0; i--) {
            cur += a[i];
            if (cur >= v) {
                r[idx] = r[idx - 1] + cur;
                cur = 0;
                idx++;
            }
        }

        ll ans = -1, sum = accumulate(a.begin(), a.end(), 0ll);
        for (int i = 0; i <= m; i++) {
            if (l[i] < 0 || r[m - i] < 0) continue;
            ans = max(ans, sum - l[i] - r[m - i]);
        }
        cout << ans << '\n';
    }
}