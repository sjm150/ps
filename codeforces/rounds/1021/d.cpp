#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 1e9 + 7;
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<pair<int, int>> xy(k + 1);
        for (auto &[x, y]: xy) {
            cin >> x >> y;
            x--, y--;
        }

        long long ans = 1;
        int sz = n * m;
        vector<vector<int>> edges(sz);
        for (int i = 0; i < k; i++) {
            auto [px, py] = xy[i];
            auto [x, y] = xy[i + 1];
            int dx = abs(px - x), dy = abs(py - y);
            if (dx == 1 && dy == 1) {
                int u = px * m + y, v = x * m + py;
                edges[u].push_back(v);
                edges[v].push_back(u);
            } else if (dx + dy == 2) {
                int u = (px + x) / 2 * m + (py + y) / 2;
                edges[u].push_back(u);
                edges[u].push_back(u);
            } else {
                ans = 0;
            }
        }

        vector<bool> vst(sz, false);
        auto sdfs = [&](int s) {
            bool loop = false;
            int vcnt = 0, ecnt = 0;
            function<void(int)> dfs = [&](int cur) {
                vst[cur] = true;
                vcnt++;
                ecnt += edges[cur].size();
                for (int nxt: edges[cur]) {
                    if (nxt == cur) loop = true;
                    if (!vst[nxt]) dfs(nxt);
                }
            };
            dfs(s);
            return make_tuple(loop, vcnt, ecnt / 2);
        };
        for (int i = 0; i < sz; i++) {
            if (vst[i]) continue;
            auto [loop, vcnt, ecnt] = sdfs(i);
            if (vcnt < ecnt) ans = 0;
            else if (vcnt == ecnt) ans = ans * (loop ? 1 : 2) % mod;
            else ans = ans * vcnt % mod;
        }

        cout << ans << '\n';
    }
}