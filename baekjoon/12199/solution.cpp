#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int m, n; cin >> m >> n;
        vector<int> cnt(m + 1, 0);
        cnt[1] = m;
        for (n--; n--;) {
            for (int i = m; i > 1; i--) cnt[i] = (ll(cnt[i]) * i + ll(cnt[i - 1]) * (m - i + 1)) % mod;
        }
        cout << "Case #" << tt << ": " << cnt[m] << '\n';
    }
}