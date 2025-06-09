#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 1e9 + 7;
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        auto solve = [&]() {
            vector<int> leaf;
            for (int i = 1; i < n; i++) {
                if (edges[i].size() == 1) leaf.push_back(i);
            }
            if (leaf.size() > 2) return 0;
            if (leaf.size() == 1) {
                int ans = 1;
                for (int i = 0; i < n; i++) ans = ans * 2 % mod;
                return ans;
            }

            vector<int> h(n);
            function<void(int, int)> dfs = [&](int pre, int cur) {
                for (int nxt: edges[cur]) {
                    if (nxt == pre) continue;
                    h[nxt] = h[cur] + 1;
                    dfs(cur, nxt);
                }
            };
            h[0] = 1;
            dfs(-1, 0);

            int l1 = leaf[0], l2 = leaf[1], br = 0;
            if (edges[br].size() < 2) {
                int pre = -1;
                while (edges[br].size() < 3) {
                    if (edges[br][0] != pre) {
                        pre = br;
                        br = edges[br][0];
                    } else {
                        pre = br;
                        br = edges[br][1];
                    }
                }
            }

            if (h[l1] == h[l2]) {
                int ans = 1;
                for (int i = 0; i < h[br] + 1; i++) ans = ans * 2 % mod;
                return ans;
            } else {
                int ans = 1;
                for (int i = 0; i < h[br] + abs(h[l1] - h[l2]) - 1; i++) ans = ans * 2 % mod;
                return ((ans + ans) % mod + ans) % mod;
            }
        };

        cout << solve() << '\n';
    }
}