#include <bits/stdc++.h>
using namespace std;

typedef struct Edge {
    int nxt, c, f, rev;
    Edge(int nxt, int c, int rev): nxt(nxt), c(c), f(0), rev(rev) {}
} e_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    int s = -1, e = -1;
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'K') {
                s = i * m + j + n * m;
                sx = i, sy = j;
            } else if (grid[i][j] == 'H') {
                e = i * m + j;
            }
        }
    }
    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};
    for (int d = 0; d < 4; d++) {
        int nx = sx + dx[d];
        int ny = sy + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (grid[nx][ny] == 'H') {
            cout << -1 << '\n';
            return 0;
        }
    }

    int sz = n * m;
    vector<vector<e_t>> edges(sz * 2);
    auto add = [&](int u, int v, int c) {
        edges[u].emplace_back(v, c, edges[v].size());
        edges[v].emplace_back(u, 0, edges[u].size() - 1);
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') continue;
            int u = i * m + j;
            add(u, u + sz, 1);
            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#') continue;
                add(u + sz, nx * m + ny, 1);
            }
        }
    }

    int ans = 0;
    for (;;) {
        vector<int> pre(sz * 2, -1), pth(sz * 2, -1);
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int i = 0; i < edges[cur].size(); i++) {
                auto &[nxt, c, f, rev] = edges[cur][i];
                if (pre[nxt] < 0 && c - f > 0) {
                    pre[nxt] = cur;
                    pth[nxt] = i;
                    q.push(nxt);
                }
            }
        }
        if (pre[e] < 0) break;

        int mn = 1e9;
        for (int i = e; i != s; i = pre[i]) {
            auto &e = edges[pre[i]][pth[i]];
            mn = min(mn, e.c - e.f);
        }
        for (int i = e; i != s; i = pre[i]) {
            auto &e = edges[pre[i]][pth[i]];
            e.f += mn;
            edges[i][e.rev].f -= mn;
        }
        ans += mn;
    }
    cout << ans << '\n';
}