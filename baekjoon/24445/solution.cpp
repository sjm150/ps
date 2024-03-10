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
    for (auto &e: edges) sort(e.begin(), e.end(), greater<int>());

    vector<int> vst(n + 1, 0);
    int v = 1;
    queue<int> q;
    vst[r] = v++;
    q.push(r);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt: edges[cur]) {
            if (!vst[nxt]) {
                vst[nxt] = v++;
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << vst[i] << '\n';
}