#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m, n; cin >> m >> n;
    int sz = m + n + 2;
    const int s = m + n, e = m + n + 1;
    const int inf = 1e9;

    vector<vector<int>> c(sz, vector<int>(sz, 0)), f(sz, vector<int>(sz, 0)), edges(sz);
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        c[s][i] = t;
        edges[s].push_back(i);
        edges[i].push_back(s);
    }

    vector<int> pre(m, -1);
    for (int i = 0; i < n; i++) {
        int u = m + i;
        int a; cin >> a;
        vector<int> k(a);

        for (int &k: k) {
            cin >> k;
            k--;
            if (pre[k] == u) continue;
            if (pre[k] >= 0) {
                c[pre[k]][u] = inf;
                edges[pre[k]].push_back(u);
                edges[u].push_back(pre[k]);
            }
            pre[k] = u;
        }

        int b; cin >> b;
        for (int k: k) {
            c[k][u] = inf;
            c[u][e] = b;
            edges[k].push_back(u);
            edges[u].push_back(k);
            edges[u].push_back(e);
            edges[e].push_back(u);
        }
    }

    int ans = 0;
    for (;;) {
        vector<int> pre(sz, -1);
        queue<int> q;
        q.push(s);
        while (!q.empty() && pre[e] < 0) {
            int cur = q.front(); q.pop();
            for (int nxt: edges[cur]) {
                if (c[cur][nxt] - f[cur][nxt] > 0 && pre[nxt] < 0) {
                    pre[nxt] = cur;
                    q.push(nxt);
                    if (nxt == e) break;
                }
            }
        }
        if (pre[e] < 0) break;

        int flo = inf;
        for (int i = e; i != s; i = pre[i]) flo = min(flo, c[pre[i]][i] - f[pre[i]][i]);
        for (int i = e; i != s; i = pre[i]) {
            f[pre[i]][i] += flo;
            f[i][pre[i]] -= flo;
        }
        ans += flo;
    }

    cout << ans << '\n';
}