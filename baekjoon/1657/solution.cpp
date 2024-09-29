#include <bits/stdc++.h>
using namespace std;

typedef struct Edge {
    int t, d, r, c;
    Edge(int t, int d, int r, int c): t(t), d(d), r(r), c(c) {}
} e_t;

const int cst[5][5] = {{10, 8, 7, 5, 1}, {8, 6, 4, 3, 1}, {7, 4, 3, 2, 1}, {5, 3, 2, 2, 1}, {1, 1, 1, 1, 0}};
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> grd(n, vector<int>(m));
    for (auto &g: grd) {
        for (int &g: g) {
            char c; cin >> c;
            if (c == 'F') g = 4;
            else g = c - 'A';
        }
    }

    int sz = n * m + 2;
    int s = sz - 2, e = sz - 1;
    vector<vector<e_t>> edges(sz);
    auto adde = [&](int u, int v, int d) {
        edges[u].emplace_back(v, d, edges[v].size(), 1);
        edges[v].emplace_back(u, -d, edges[u].size() - 1, 0);
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = i * m + j;
            if ((i + j) % 2) {
                adde(u, e, 0);
            } else {
                adde(s, u, 0);
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    adde(u, nx * m + ny, -cst[grd[i][j]][grd[nx][ny]]);
                }
            }
        }
    }

    int ans = 0, val = 0;
    for (;;) {
        vector<int> pth(sz, -1), dst(sz, inf);
        vector<bool> inq(sz, false);
        queue<int> q;
        dst[s] = 0;
        inq[s] = true;
        q.push(s);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            inq[cur] = false;
            for (auto &[nxt, d, r, c]: edges[cur]) {
                if (c > 0 && dst[nxt] > dst[cur] + d) {
                    pth[nxt] = r;
                    dst[nxt] = dst[cur] + d;
                    if (!inq[nxt]) {
                        inq[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
        if (pth[e] == -1) break;

        val -= dst[e];
        ans = max(ans, val);
        for (int cur = e; cur != s;) {
            e_t &r = edges[cur][pth[cur]];
            e_t &e = edges[r.t][r.r];
            e.c--;
            r.c++;
            cur = r.t;
        }
    }
    cout << ans << '\n';
}