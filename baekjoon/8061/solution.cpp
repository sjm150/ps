#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<string> bm(n);
    for (auto &s: bm) cin >> s;

    queue<pair<int, int>> q;
    vector<vector<int>> dst(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (bm[i][j] == '0') continue;
            q.emplace(i, j);
            dst[i][j] = 0;
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy]: {make_pair(-1, 0), {1, 0}, {0, -1}, {0, 1}}) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || dst[nx][ny] >= 0) continue;
            q.emplace(nx, ny);
            dst[nx][ny] = dst[x][y] + 1;
        }
    }

    for (auto &d: dst) {
        for (int d: d) cout << d << ' ';
        cout << '\n';
    }
}