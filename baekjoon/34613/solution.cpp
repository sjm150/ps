#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int r, c, n, p;
    cin >> r >> c >> n >> p;
    vector<vector<int>> g(r, vector<int>(c));
    int px = -1, py = -1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> g[i][j];
            if (g[i][j] == p) px = i, py = j;
        }
    }

    vector<bool> adj(n, false);
    for (int x = px, y = py; x >= 0;) {
        int xx = -1, yy = -1;
        for (auto [dx, dy]: {make_pair(-1, 0), {1, 0}, {0, -1}, {0, 1}}) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || g[nx][ny] == 0) continue;
            int d = g[nx][ny] - g[x][y];
            if (0 < d + p && d + p <= n) adj[d + p - 1] = true;
            if (d == -1) xx = nx, yy = ny;
        }
        x = xx, y = yy;
    }

    cout << accumulate(adj.begin(), adj.end(), 0) << '/' << n - 1 << '\n';
}