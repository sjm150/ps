#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> w(n);
        for (int &w: w) cin >> w;
        vector<vector<int>> edges(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        vector<int> in(n), out(n);
        int tm = 0;
        function<void(int, int)> dfs = [&](int pre, int cur) {
            in[cur] = tm++;
            for (int nxt: edges[cur]) {
                if (nxt == pre) continue;
                dfs(cur, nxt);
            }
            out[cur] = tm++;
        };
        dfs(0, 0);

        vector<pair<int, int>> ord(n);
        for (int i = 0; i < n; i++) ord[i] = {w[i], i};
        sort(ord.begin(), ord.end(), greater<pair<int, int>>());
        vector<int> is(n), os(n);
        is[ord[0].second] = in[ord[0].second];
        os[ord[0].second] = out[ord[0].second];
        for (int i = 1; i < n; i++) {
            is[ord[i].second] = min(is[ord[i - 1].second], in[ord[i].second]);
            os[ord[i].second] = max(os[ord[i - 1].second], out[ord[i].second]);
        }

        int pre = -1;
        int ans = -1;
        for (int i = 1; i < n; i++) {
            if (ord[i - 1].first != ord[i].first) pre = i - 1;
            if (pre < 0) continue;
            auto [pw, pi] = ord[pre];
            auto [cw, ci] = ord[i];
            if (is[pi] < in[ci] || out[ci] < os[pi]) {
                ans = ci;
                break;
            }
        }
        cout << ans + 1 << '\n';
    }
}