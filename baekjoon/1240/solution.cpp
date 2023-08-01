#include <iostream>
#include <vector>
typedef long long lint;
using namespace std;

vector<pair<int, int>> edges[1001];
int dst(int cur, int pre, int tar) {
    if (cur == tar) return 0;
    for (auto [nxt, d]: edges[cur]) {
        if (pre == nxt) continue;
        int dn = dst(nxt, cur, tar);
        if (dn >= 0) return d + dn;
    }
    return -1;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int u, v, d; cin >> u >> v >> d;
        edges[u].emplace_back(v, d);
        edges[v].emplace_back(u, d);
    }
    while (m--) {
        int u, v; cin >> u >> v;
        cout << dst(u, 0, v) << '\n';
    }
}