#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, f, t, s; cin >> n >> m >> f >> t >> s;
    vector<vector<int>> edges(n);
    while (m--) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    if (t == s) {
        cout << "death\n";
        exit(0);
    }

    vector<vector<int>> tdst(n, vector<int>(2, inf));
    queue<pair<int, int>> tq;
    tdst[t][0] = 0;
    tq.emplace(t, 0);
    while (!tq.empty()) {
        auto [cur, d] = tq.front(); tq.pop();
        d++;
        for (int nxt: edges[cur]) {
            if (tdst[nxt][d % 2] > d) {
                tdst[nxt][d % 2] = d;
                tq.emplace(nxt, d);
            }
        }
    }

    vector<int> dst(n, inf);
    queue<int> q;
    dst[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int d[2] = {dst[cur] + 1, dst[cur] + 2};
        for (int nxt: edges[cur]) {
            for (int d: d) {
                if (dst[nxt] > d && tdst[nxt][d % 2] > d) {
                    dst[nxt] = d;
                    q.push(nxt);
                }
            }
        }
    }

    if (dst[f] < inf) cout << dst[f] << '\n';
    else cout << "death\n";
}