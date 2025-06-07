#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n;
    cin >> n;
    vector<int> x(n);
    for (int &x: x) cin >> x;
    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[u].emplace_back(w, v);
        edges[v].emplace_back(w, u);
    }

    ll ans = 0;
    function<void(int, int)> dfs = [&](int pre, int cur) {
        for (auto [w, nxt]: edges[cur]) {
            if (nxt == pre) continue;
            dfs(cur, nxt);
            ans += ll(abs(x[nxt])) * w;
            x[cur] += x[nxt];
        }
    };
    dfs(-1, 0);
    cout << ans << '\n';
}