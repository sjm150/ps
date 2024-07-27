#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k; cin >> k;
    while (k--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges(n), c(n, vector<int>(n, 0)), f(n, vector<int>(n, 0));
        vector<pair<int, int>> es;
        while (m--) {
            int f, t, b; cin >> f >> t >> b;
            f--, t--;
            edges[f].push_back(t);
            edges[t].push_back(f);
            c[f][t] += b;
            es.emplace_back(f, t);
        }

        for (;;) {
            vector<int> pre(n, -1);
            queue<int> q;
            q.push(0);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int nxt: edges[cur]) {
                    if (c[cur][nxt] - f[cur][nxt] > 0 && pre[nxt] < 0) {
                        pre[nxt] = cur;
                        q.push(nxt);
                    }
                }
            }
            if (pre[n - 1] < 0) break;
            int mn = inf;
            for (int i = n - 1; i != 0; i = pre[i]) mn = min(mn, c[pre[i]][i] - f[pre[i]][i]);
            for (int i = n - 1; i != 0; i = pre[i]) {
                f[pre[i]][i] += mn;
                f[i][pre[i]] -= mn;
            }
        }

        int cnt = 0;
        for (auto &[s, e]: es) {
            if (c[s][e] != f[s][e]) continue;
            c[s][e]--;
            vector<int> pre(n, -1);
            queue<int> q;
            q.push(s);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int nxt: edges[cur]) {
                    if (c[cur][nxt] - f[cur][nxt] > 0 && pre[nxt] < 0) {
                        pre[nxt] = cur;
                        q.push(nxt);
                    }
                }
            }
            if (pre[e] < 0) cnt++;
            c[s][e]++;
        }
        cout << cnt << '\n';
    }
}