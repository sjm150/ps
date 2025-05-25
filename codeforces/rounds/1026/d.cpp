#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll inf = 2e14 + 5;
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> b(n);
        for (int &b: b) cin >> b;
        vector<vector<pair<int, int>>> edges(n);
        while (m--) {
            int s, t, w;
            cin >> s >> t >> w;
            edges[s - 1].emplace_back(w, t - 1);
        }

        ll l = 0, r = inf;
        while (l < r) {
            ll m = (l + r) / 2;
            vector<ll> sum(n, -1);
            sum[0] = b[0];
            for (int i = 0; i < n - 1; i++) {
                for (auto [w, j]: edges[i]) {
                    if (w > min(m, sum[i])) continue;
                    sum[j] = max(sum[j], sum[i] + b[j]);
                }
            }
            if (sum[n - 1] < 0) l = m + 1;
            else r = m;
        }

        cout << (r < inf ? r : -1) << '\n';
    }
}