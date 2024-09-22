#include <bits/stdc++.h>
using namespace std;

typedef struct Edge {
    int t, d, r, c;
    Edge(int t, int d, int r, int c): t(t), d(d), r(r), c(c) {}
} e_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<vector<int>> f(n, vector<int>(n));
    for (auto &f: f) {
        for (int &f: f) cin >> f;
    }

    int sz = n * n + 2;
    int s = sz - 2, e = sz - 1;
    vector<vector<e_t>> edges(sz);
    auto adde = [&](int v, int u, int d) {
        edges[v].emplace_back(u, d, edges[u].size(), 1);
        edges[u].emplace_back(v, -d, edges[v].size() - 1, 0);
    };

    vector<tuple<int, int, int>> cnd;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v = i * n + j;
            if ((i + j) % 2) {
                adde(v, e, 0);
            } else {
                adde(s, v, 0);
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    cnd.emplace_back(-f[i][j] - f[nx][ny], v, nx * n + ny);
                }
            }
        }
    }
    sort(cnd.begin(), cnd.end());
    for (int i = 0; i < min(100, int(cnd.size())); i++) {
        auto &[d, v, u] = cnd[i];
        adde(v, u, d);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) ans += accumulate(f[i].begin(), f[i].end(), 0);
    while (k--) {
        vector<int> pth(sz, -1), dst(sz, 1e9);
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
                    dst[nxt] = dst[cur] + d;
                    pth[nxt] = r;
                    if (!inq[nxt]) {
                        inq[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
        if (pth[e] == -1) break;

        for (int cur = e; cur != s;) {
            auto &r = edges[cur][pth[cur]];
            auto &e = edges[r.t][r.r];
            ans += e.d;
            e.c--;
            r.c++;
            cur = r.t;
        }
    }

    cout << ans << '\n';
}