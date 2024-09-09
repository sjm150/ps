#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int c, b; cin >> c >> b;
        vector<vector<int>> edges(c);
        for (int i = 0; i < b; i++) {
            int u, v; cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        if (b == 0) {
            cout << 1 << '\n';
            continue;
        }

        auto chk = [&](int d) {
            vector<int> vst(c, -1);
            bool chk[2][2] = {};
            function<bool(int, int)> dfs = [&](int cur, int v) {
                vst[cur] = v;
                int m = (d >> cur) & 1;
                chk[m][v] = true;
                for (int nxt: edges[cur]) {
                    if (m != ((d >> nxt) & 1)) continue;
                    if (vst[nxt] < 0) {
                        if (!dfs(nxt, 1 - v)) return false;
                    } else if (vst[nxt] == vst[cur]) {
                        return false;
                    }
                }
                return true;
            };
            for (int i = 0; i < c; i++) {
                if (vst[i] < 0 && !dfs(i, 0)) return 5;
            }
            int cnt = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) cnt += chk[i][j];
            }
            return cnt;
        };

        int ans = 5;
        for (int i = 0; i < (1 << c); i++) ans = min(ans, chk(i));
        if (ans < 5) cout << ans << '\n';
        else cout << "many\n";
    }
}