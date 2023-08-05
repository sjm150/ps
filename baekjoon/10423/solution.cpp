#include <bits/stdc++.h>
using namespace std;

bool plant[1001];
vector<tuple<int, int, int>> edges;
int p[1001];

int find(int v) {
    if (p[v] == 0) return v;
    return p[v] = find(p[v]);
}
bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v || (plant[u] && plant[v])) return false;
    if (plant[u]) p[v] = u;
    else p[u] = v;
    return true;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    while (k--) {
        int v; cin >> v;
        plant[v] = true;
    }
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    int sum = 0;
    for (auto [w, u, v]: edges) {
        if (uni(u, v)) sum += w;
    }
    cout << sum << '\n';
}