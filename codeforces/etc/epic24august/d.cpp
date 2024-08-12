#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n + 1), p(n + 1);
        vector<vector<int>> edges(n + 1);
        a[1] = 0;
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
            edges[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++) cin >> p[i];

        vector<int> h(n + 1);
        vector<vector<int>> anc(1, vector<int>(n + 1, -1));
        int maxh = h[1] = 0;
        function<void(int)> dfs = [&](int cur) {
            for (int nxt: edges[cur]) {
                h[nxt] = h[cur] + 1;
                maxh = max(maxh, h[nxt]);
                anc[0][nxt] = cur;
                dfs(nxt);
            }
        };
        dfs(1);
        for (int i = 2; i <= maxh; i *= 2) anc.push_back(vector<int>(n + 1, -1));
        for (int i = 1; i < anc.size(); i++) {
            for (int j = 1; j <= n; j++) {
                if (anc[i - 1][j] < 0) continue;
                anc[i][j] = anc[i - 1][anc[i - 1][j]];
            }
        }

        function<int(int, int)> lca = [&](int u, int v) {
            if (h[u] < h[v]) return lca(v, u);
            int dh = h[u] - h[v];
            for (int i = 0; dh; i++) {
                if (dh % 2) u = anc[i][u];
                dh /= 2;
            }
            if (u == v) return u;
            for (int i = anc.size() - 1; i >= 0; i--) {
                if (anc[i][u] == anc[i][v]) continue;
                u = anc[i][u];
                v = anc[i][v];
            }
            return anc[0][u];
        };

        vector<bool> ok(n + 1, false);
        int cnt = 0;
        auto chk = [&](int i) {
            if (i == 1) {
                if (p[i] == 1) {
                    if (!ok[p[i]]) cnt++;
                    ok[p[i]] = true;
                } else {
                    if (ok[p[i]]) cnt--;
                    ok[p[i]] = false;
                }
                return;
            }
            if (p[i] == 1) {
                if (ok[p[i]]) cnt--;
                ok[p[i]] = false;
                return;
            }
            if (lca(p[i - 1], p[i]) == a[p[i]]) {
                if (!ok[p[i]]) cnt++;
                ok[p[i]] = true;
            } else {
                if (ok[p[i]]) cnt--;
                ok[p[i]] = false;
            }
        };
        for (int i = 1; i <= n; i++) chk(i);
        
        while (q--) {
            int x, y; cin >> x >> y;
            swap(p[x], p[y]);
            chk(x);
            chk(y);
            if (x < n) chk(x + 1);
            if (y < n) chk(y + 1);
            cout << (cnt == n ? "YES\n" : "NO\n");
        }
    }
}