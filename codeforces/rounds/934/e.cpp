#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> edges(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        vector<bool> blk(n + 1, false);
        int maxd, maxr;
        vector<int> h(n + 1), maxn(n + 1);
        function<int(int, int)> dfs = [&](int pre, int cur) {
            int maxh[2] = {0, 0};
            maxn[cur] = 0;
            for (int nxt: edges[cur]) {
                if (pre == nxt || blk[nxt]) continue;
                int h = dfs(cur, nxt);
                if (maxh[0] < h) {
                    maxh[1] = maxh[0];
                    maxh[0] = h;
                    maxn[cur] = nxt;
                } else if (maxh[1] < h) {
                    maxh[1] = h;
                }
            }
            if (maxd < maxh[0] + maxh[1]) {
                maxd = maxh[0] + maxh[1];
                maxr = cur;
            }
            return h[cur] = maxh[0] + 1;
        };

        int wcnt = n;
        function<void(int, int, int)> cdfs = [&](int pre, int cur, int d) {
            if (d == maxd / 2 && !blk[cur]) {
                blk[cur] = true;
                wcnt--;
            }
            for (int nxt: edges[cur]) {
                if (pre != nxt) cdfs(cur, nxt, d + 1);
            }
        };

        int ans = 0;
        vector<pair<int, int>> ops;
        while (wcnt > 1) {
            maxd = 0;
            for (int i = 1; i <= n; i++) {
                if (!blk[i]) {
                    maxr = i;
                    dfs(0, i);
                    break;
                }
            }

            int maxp = maxr;
            while (h[maxr] - 1 > maxd / 2) {
                maxp = maxr;
                maxr = maxn[maxr];
            }

            ans++;
            ops.emplace_back(maxr, maxd / 2);
            cdfs(0, maxr, 0);
            if (maxd & 1) {
                ans++;
                ops.emplace_back(maxp, maxd / 2);
                cdfs(0, maxp, 0);
            }
        }

        if (wcnt) {
            for (int i = 1; i <= n; i++) {
                if (!blk[i]) {
                    ans++;
                    ops.emplace_back(i, 0);
                    break;
                }
            }
        }

        cout << ans << '\n';
        for (auto [v, d]: ops) cout << v << ' ' << d << '\n';
    }
}