#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    while (m--) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> cnts[2];
    int cur = 0, nxt = 1;
    cnts[0] = vector<int>(n + 1, 1);
    cnts[1] = vector<int>(n + 1);

    for (int i = 0; i < 7; i++) {
        fill(cnts[nxt].begin(), cnts[nxt].end(), 0);
        for (int u = 1; u <= n; u++) {
            for (int v: edges[u]) {
                cnts[nxt][v] += cnts[cur][u];
                if (cnts[nxt][v] >= mod) cnts[nxt][v] -= mod;
            }
        }
        swap(cur, nxt);
    }

    int sum = 0;
    for (int u = 1; u <= n; u++) {
        sum += cnts[cur][u];
        if (sum >= mod) sum -= mod;
    }
    cout << sum << '\n';
}