#include <bits/stdc++.h>
using namespace std;
const int inf = 123456789;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, p; cin >> n >> p;
    int sz = 2 * n + 1;
    vector<vector<int>> adj(sz), c(sz, vector<int>(sz, 0)), f(sz, vector<int>(sz, 0));
    for (int i = 3; i <= n; i++) {
        adj[i].push_back(i + n);
        adj[i + n].push_back(i);
        c[i + n][i] = 1;
    }
    while (p--) {
        int u, v; cin >> u >> v;
        if (c[u][v + n] == 0) {
            adj[u].push_back(v + n);
            adj[v + n].push_back(u);
            adj[v].push_back(u + n);
            adj[u + n].push_back(v);
            c[u][v + n] = c[v][u + n] = 1;
        }
    }

    int tot = 0;
    vector<int> pre(sz);
    while (true) {
        queue<int> q;
        fill(pre.begin(), pre.end(), -1);
        pre[1] = 0;
        q.push(1);
        while (!q.empty() && pre[2 + n] < 0) {
            int cur = q.front(); q.pop();
            for (int nxt: adj[cur]) {
                if (pre[nxt] >= 0 || c[cur][nxt] <= f[cur][nxt]) continue;
                pre[nxt] = cur;
                q.push(nxt);
            }
        }
        if (pre[2 + n] < 0) break;

        int flw = inf;
        for (int cur = 2 + n; pre[cur]; cur = pre[cur]) flw = min(flw, c[pre[cur]][cur] - f[pre[cur]][cur]);
        for (int cur = 2 + n; pre[cur]; cur = pre[cur]) {
            f[pre[cur]][cur] += flw;
            f[cur][pre[cur]] -= flw;
        }
        tot += flw;
    }

    cout << tot << '\n';
}