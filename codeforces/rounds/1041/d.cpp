#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mod = 1e9 + 7, mx = 2e5;
    vector<ll> f(mx + 1);
    f[0] = 1;
    for (int i = 1; i <= mx; i++) f[i] = f[i - 1] * i % mod;

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(n);
        while (m--) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        vector<int> bs;
        vector<vector<int>> be(n);
        for (int i = 0; i < n; i++) {
            if (edges[i].size() == 1) continue;
            bs.push_back(i);
            for (int j: edges[i]) {
                if (edges[j].size() > 1) be[i].push_back(j);
            }
        }

        auto solve = [&]() {
            if (n == 2) return 2ll;
            if (bs.size() == 1) return f[edges[bs[0]].size()] * 2 % mod;

            vector<int> en;
            for (int b: bs) {
                if (be[b].size() == 1) en.push_back(b);
                else if (be[b].size() > 2) return 0ll;
            }
            if (en.size() != 2) return 0ll;

            ll ans = 4;
            for (int b: bs) ans = ans * f[edges[b].size() - 2 + (b == en[0] || b == en[1])] % mod;
            return ans;
        };

        cout << solve() << '\n';
    }
}