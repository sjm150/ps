#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> g(r, vector<int>(c));
        for (auto &g: g) {
            for (int &g: g) cin >> g;
        }

        long long ans = 0;
        priority_queue<tuple<int, int, int>> pq;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) pq.emplace(g[i][j], i, j);
        }
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();
            if (g[x][y] > h) continue;
            for (auto [dx, dy]: {make_pair(-1, 0), {1, 0}, {0, -1}, {0, 1}}) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (g[nx][ny] < h - 1) {
                    ans += h - 1 - g[nx][ny];
                    g[nx][ny] = h - 1;
                    pq.emplace(h - 1, nx, ny);
                }
            }
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }
}