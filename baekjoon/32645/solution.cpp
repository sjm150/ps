#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<bool> w(n, false);
    function<void(int, int)> dfs = [&](int pre, int cur) {
        for (int nxt: edges[cur]) {
            if (nxt == pre) continue;
            dfs(cur, nxt);
            if (!w[nxt]) w[cur] = true;
        }
    };
    dfs(-1, 0);
    for (int i = 0; i < n; i++) cout << (w[i] ? "donggggas\n" : "uppercut\n");
}