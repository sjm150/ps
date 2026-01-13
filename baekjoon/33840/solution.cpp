#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
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

    vector<int> sz(n);
    function<void(int, int)> dfs = [&](int pre, int cur) {
        sz[cur] = 1;
        for (int nxt: edges[cur]) {
            if (pre == nxt) continue;
            dfs(cur, nxt);
            sz[cur] += sz[nxt];
        }
    };
    dfs(-1, 0);

    int c = 0;
    for (;;) {
        bool ok = true;
        for (int nxt: edges[c]) {
            if (sz[nxt] > sz[c]) continue;
            if (sz[nxt] * 2 > n) {
                c = nxt;
                ok = false;
                break;
            }
        }
        if (ok) break;
    }

    dfs(-1, c);
    function<bool(int, int)> chk = [&](int pre, int cur) {
        for (int nxt: edges[cur]) {
            if (pre == nxt) continue;
            if (sz[nxt] * 2 > sz[cur]) return false;
            if (!chk(cur, nxt)) return false;
        }
        return true;
    };
    function<void(int, int)> prnt = [&](int pre, int cur) {
        for (int nxt: edges[cur]) {
            if (pre == nxt) continue;
            cout << cur + 1 << ' ' << nxt + 1 << '\n';
            prnt(cur, nxt);
        }
    };

    if (chk(-1, c)) prnt(-1, 0);
    else cout << -1 << '\n';
}