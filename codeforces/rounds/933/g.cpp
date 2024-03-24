#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        map<int, int> cc;
        vector<vector<int>> edges(n + 1);
        while (m--) {
            int u, v, c; cin >> u >> v >> c;
            auto it = cc.find(c);
            if (it != cc.end()) {
                c = it->second;
            } else {
                cc[c] = edges.size();
                c = edges.size();
                edges.emplace_back();
            }
            edges[u].push_back(c);
            edges[v].push_back(c);
            edges[c].push_back(u);
            edges[c].push_back(v);
        }
        int b, e; cin >> b >> e;

        int sz = edges.size();
        vector<int> dst(sz, -1);
        queue<int> q;
        dst[b] = 0;
        q.push(b);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt: edges[cur]) {
                if (dst[nxt] < 0) {
                    dst[nxt] = dst[cur] + 1;
                    q.push(nxt);
                }
            }
        }

        cout << dst[e] / 2 << '\n';
    }
}