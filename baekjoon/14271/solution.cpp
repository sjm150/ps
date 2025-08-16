#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int inf = 1e9;
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &g: grid) cin >> g;
    int k;
    cin >> k;

    int r = n + k * 2, c = m + k * 2;
    vector<vector<int>> dst(r, vector<int>(c, inf));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'o') {
                dst[i + k][j + k] = 0;
                q.emplace(i + k, j + k);
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy]: {make_pair(-1, 0), {1, 0}, {0, -1}, {0, 1}}) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (dst[nx][ny] == inf) {
                dst[nx][ny] = dst[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }

    int ans = 0;
    for (auto &d: dst) {
        for (int d: d) ans += d <= k;
    }
    cout << ans << '\n';
}