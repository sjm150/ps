#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mx = 2e5;
    vector<bool> isp(mx + 1, true);
    isp[0] = isp[1] = false;
    for (ll i = 2; i <= mx; i++) {
        if (!isp[i]) continue;
        for (ll j = i * i; j <= mx; j += i) isp[j] = false;
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> edges(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        vector<int> a(n);
        int v = 1;
        function<void(int, int)> init = [&](int pre, int cur) {
            a[cur] = v++ * 2;
            for (int nxt: edges[cur]) {
                if (nxt == pre) continue;
                init(cur, nxt);
            }
        };
        init(-1, 0);

        function<void(int, int, bool)> dfs = [&](int pre, int cur, bool sub) {
            for (int nxt: edges[cur]) {
                if (nxt == pre) continue;
                if (a[nxt] - a[cur] == 2) {
                    if (sub) {
                        a[nxt] = a[cur];
                        dfs(cur, nxt, false);
                    } else {
                        dfs(cur, nxt, true);
                    }
                } else {
                    dfs(cur, nxt, sub);
                }
            }
            if (sub) a[cur]--;
        };
        dfs(-1, 0, false);

        for (int a: a) cout << a << ' ';
        cout << '\n';
    }
}