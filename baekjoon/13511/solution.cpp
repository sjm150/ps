#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> edges;
int maxh, maxk;
vector<int> h;
vector<ll> dst;
vector<vector<int>> anc;

void dfs(int pre, int cur) {
    if (h[cur] > maxh) maxh = h[cur];
    anc[0][cur] = pre;
    for (auto &[w, nxt]: edges[cur]) {
        if (pre == nxt) continue;
        h[nxt] = h[cur] + 1;
        dst[nxt] = dst[cur] + w;
        dfs(cur, nxt);
    }
}

int lca(int u, int v) {
    if (h[u] < h[v]) return lca(v, u);
    int dh = h[u] - h[v];
    for (int k = 0; dh; k++) {
        if (dh & 1) u = anc[k][u];
        dh >>= 1;
    }
    if (u == v) return u;

    for (int k = maxk - 1; k >= 0; k--) {
        if (anc[k][u] == anc[k][v]) continue;
        u = anc[k][u];
        v = anc[k][v];
    }
    return anc[0][u];
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    edges.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges[u].emplace_back(w, v);
        edges[v].emplace_back(w, u);
    }

    h.resize(n + 1);
    dst.resize(n + 1);
    anc.resize(1, vector<int>(n + 1, 0));
    h[1] = dst[1] = 0;
    dfs(0, 1);

    for (int i = 1; i <= maxh; i <<= 1) maxk++;
    anc.resize(maxk, vector<int>(n + 1, 0));
    for (int k = 1; k < maxk; k++) {
        for (int i = 1; i <= n; i++) {
            anc[k][i] = anc[k - 1][anc[k - 1][i]];
        }
    }

    int m; cin >> m;
    while (m--) {
        int c; cin >> c;
        if (c == 1) {
            int u, v; cin >> u >> v;
            int a = lca(u, v);
            cout << dst[u] + dst[v] - 2 * dst[a] << '\n';
        } else {
            int u, v, k; cin >> u >> v >> k;
            k--;
            int a = lca(u, v);
            if (h[u] - h[a] >= k) {
                for (int i = 0; k; i++) {
                    if (k & 1) u = anc[i][u];
                    k >>= 1;
                }
                cout << u << '\n';
            } else {
                k = h[u] + h[v] - 2 * h[a] - k;
                for (int i = 0; k; i++) {
                    if (k & 1) v = anc[i][v];
                    k >>= 1;
                }
                cout << v << '\n';
            }
        }
    }
}