#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        vector<int> fst(k + 1, n);
        for (int i = 0; i < n; i++) {
            if (fst[a[i]] == n) fst[a[i]] = i;
        }
        for (int i = k - 1; i >= 0; i--) fst[i] = min(fst[i], fst[i + 1]);

        vector<vector<ll>> sum(k + 1, vector<ll>(k + 1, 0));
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < i; j++) {
                for (int u = 0; u + i <= k; u++) sum[i][u + i] = max(sum[i][u + i], sum[j][u] + ll(n - fst[i]) * (i - j));
            }
        }

        ll ans = 0;
        for (auto &s: sum) {
            for (ll s: s) ans = max(ans, s);
        }
        cout << ans << '\n';
    }
}