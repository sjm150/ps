#include <bits/stdc++.h>
using namespace std;
const int inf = 123456789;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, p; cin >> n >> p;
    vector<vector<int>> adj(n + 1), c(n + 1, vector<int>(n + 1, 0)), f(n + 1, vector<int>(n + 1));
    while (p--) {
        int u, v; cin >> u >> v;
        if (c[u][v] + c[v][u] == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        c[u][v]++;
    }

    int tot = 0;
    vector<int> pre(n + 1);
    while (true) {
        fill(pre.begin(), pre.end(), -1);
        queue<int> q;
        pre[1] = 0;
        q.push(1);
        while (!q.empty() && pre[2] < 0) {
            int cur = q.front(); q.pop();
            for (int nxt: adj[cur]) {
                if (pre[nxt] >= 0 || c[cur][nxt] <= f[cur][nxt]) continue;
                pre[nxt] = cur;
                q.push(nxt);
            }
        }
        if (pre[2] < 0) break;

        int flw = inf;
        for (int cur = 2; pre[cur]; cur = pre[cur]) flw = min(flw, c[pre[cur]][cur] - f[pre[cur]][cur]);
        for (int cur = 2; pre[cur]; cur = pre[cur]) {
            f[pre[cur]][cur] += flw;
            f[cur][pre[cur]] -= flw;
        }
        tot += flw;
    }

    cout << tot << '\n';
}