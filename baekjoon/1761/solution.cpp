#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int n, maxh;
int dst[40001], h[40001];
vector<vector<pi>> edges;
vector<vector<int>> anc;

void dfs(int pre, int cur) {
    for (auto [w, nxt]: edges[cur]) {
        if (pre == nxt) continue;
        anc[0][nxt] = cur;
        dst[nxt] = dst[cur] + w;
        h[nxt] = h[cur] + 1;
        if (maxh < h[nxt]) maxh = h[nxt];
        dfs(cur, nxt);
    }
}

void init_anc() {
    anc.push_back(vector<int>(n + 1, -1));
    dfs(-1, 1);
    for (int i = 2; i <= maxh; i <<= 1) anc.push_back(vector<int>(n + 1, -1));
    for (int i = 1; i < anc.size(); i++) {
        for (int j = 1; j <= n; j++) {
            if (anc[i - 1][j] >= 0) {
                anc[i][j] = anc[i - 1][anc[i - 1][j]];
            }
        }
    }
}

int lca(int u, int v) {
    if (h[u] < h[v]) return lca(v, u);
    for (int i = anc.size() - 1; i >= 0; i--) {
        if ((1 << i) <= h[u] - h[v]) u = anc[i][u];
    }
    if (u == v) return u;
    for (int i = anc.size() - 1; i >= 0; i--) {
        if (anc[i][u] != anc[i][v]) {
            u = anc[i][u];
            v = anc[i][v];
        }
    }
    return anc[0][u];
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    edges = vector<vector<pi>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges[u].emplace_back(w, v);
        edges[v].emplace_back(w, u);
    }
    init_anc();
    int m; cin >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        int a = lca(u, v);
        cout << dst[u] + dst[v] - 2 * dst[a] << '\n';
    }
}