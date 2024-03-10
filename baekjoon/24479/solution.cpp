#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, r; cin >> n >> m >> r;
    vector<vector<int>> edges(n + 1);
    while (m--) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (auto &e: edges) sort(e.begin(), e.end());

    vector<int> vst(n + 1, 0);
    int v = 1;
    function<void(int)> dfs = [&](int cur) {
        vst[cur] = v++;
        for (int nxt: edges[cur]) {
            if (!vst[nxt]) dfs(nxt);
        }
    };

    dfs(r);
    for (int i = 1; i <= n; i++) cout << vst[i] << '\n';
}