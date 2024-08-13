#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> ci(n);
    ll bse = 0;
    for (int i = 0; i < n; i++) {
        int c, a; cin >> c >> a;
        ci[i] = {c - a, i};
        bse += ll(n - 1) * a;
    }
    sort(ci.begin(), ci.end());
    ll k = 1, f = 1;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (ci[i - 1].first != ci[i].first) {
            k = k * f % mod;
            f = cnt = 1;
        } else {
            cnt++;
            f = f * cnt % mod;
        }
    }
    k = k * f % mod;

    ll ans = bse;
    for (int i = 0; i < n; i++) ans += ll(n - 1 - i) * ci[i].first;
    cout << ans << ' ' << k << '\n';
    for (int i = 0; i < n; i++) cout << ci[n - 1 - i].second + 1 << ' ';
    cout << '\n';

    ans = bse;
    for (int i = 0; i < n; i++) ans += ll(i) * ci[i].first;
    cout << ans << ' ' << k << '\n';
    for (int i = 0; i < n; i++) cout << ci[i].second + 1 << ' ';
    cout << '\n';
}