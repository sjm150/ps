#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll m; cin >> m;
        vector<pair<int, int>> ac(n);
        for (int i = 0; i < n; i++) cin >> ac[i].first;
        for (int i = 0; i < n; i++) cin >> ac[i].second;
        sort(ac.begin(), ac.end());

        ll ans = 0;
        for (auto &[a, c]: ac) {
            if (ll(a) * c <= m) ans = max(ans, ll(a) * c);
            else ans = max(ans, m / a * a);
        }
        for (int i = 1; i < n; i++) {
            if (ac[i].first - ac[i - 1].first != 1) continue;
            int a = ac[i - 1].first;
            int c1 = ac[i - 1].second, c2 = ac[i].second;
            ll mn = ll(c1) * a, mx = ll(c1 + c2) * a + c2;
            if (m <= mn) {
                ll x1 = m / a;
                ll b = x1 * a;
                ans = max(ans, min(m, b + min(x1, ll(c2))));
            } else if (mx <= m) {
                ans = max(ans, mx);
            } else {
                ll r = m - mn;
                ll x2 = r / (a + 1);
                ll b = mn + x2 * (a + 1);
                ans = max(ans, min(m, b + min(ll(c1), c2 - x2)));
            }
        }

        cout << ans << '\n';
    }
}