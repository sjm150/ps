#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int sz = n * m + 2;
        const int s = sz - 2, e = sz - 1;
        vector<vector<int>> edges(sz), c, f;
        c = f = vector<vector<int>>(sz, vector<int>(sz, 0));
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int v = m * i + j;
                int x; cin >> x;
                if ((i + j) & 1) c[v][e] = x;
                else c[s][v] = x;
                sum += x;
            }
        }
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int v = m * i + j;
                edges[s].push_back(v);
                edges[v].push_back(s);
                edges[e].push_back(v);
                edges[v].push_back(e);
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    int u = m * nx + ny;
                    if ((nx + ny) & 1) c[v][u] = inf;
                    edges[v].push_back(u);
                }
            }
        }

        int tot = 0;
        for (;;) {
            vector<int> pre(sz, -1);
            queue<int> q;
            q.push(s);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int nxt: edges[cur]) {
                    if (pre[nxt] < 0 && c[cur][nxt] - f[cur][nxt] > 0) {
                        pre[nxt] = cur;
                        q.push(nxt);
                    }
                }
            }
            if (pre[e] < 0) break;
            int mn = inf;
            for (int i = e; i != s; i = pre[i]) mn = min(mn, c[pre[i]][i] - f[pre[i]][i]);
            for (int i = e; i != s; i = pre[i]) {
                f[pre[i]][i] += mn;
                f[i][pre[i]] -= mn;
            }
            tot += mn;
        }

        cout << sum - tot << '\n';
    }
}