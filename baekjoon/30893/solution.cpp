#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, s, e; cin >> n >> s >> e;
    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    bool poss = true;
    function<bool(int, int, int)> dfs = [&](int pre, int cur, int d) {
        if (cur == e) return true;
        for (int nxt: edges[cur]) {
            if (nxt == pre) continue;
            if (dfs(cur, nxt, d + 1)) {
                if (d % 2 && edges[cur].size() > 2) poss = false;
                return true;
            }
        }
        return false;
    };
    dfs(0, s, 0);
    cout << (poss ? "First\n" : "Second\n");
}