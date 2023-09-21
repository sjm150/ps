#include <bits/stdc++.h>
using namespace std;

int n, maxh;
int h[100001];
vector<vector<int>> edges, anc;

void dfs(int pre, int cur) {
    for (int nxt: edges[cur]) {
        if (pre == nxt) continue;
        h[nxt] = h[cur] + 1;
        if (maxh < h[nxt]) maxh = h[nxt];
        anc[0][nxt] = cur;
        dfs(cur, nxt);
    }
}

void init_anc() {
    anc.push_back(vector<int>(n + 1, -1));
    dfs(-1, 1);
    for (int i = 2; i <= maxh; i <<= 1) anc.push_back(vector<int>(n + 1, -1));
    for (int i = 1; i < anc.size(); i++) {
        for (int j = 1; j <= n; j++) {
            if (anc[i - 1][j] < 0) continue;
            anc[i][j] = anc[i - 1][anc[i - 1][j]];
        }
    }
}

int lca(int u, int v) {
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
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    edges = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    init_anc();
    int m; cin >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}