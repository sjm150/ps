#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (auto &s: grid) cin >> s;
    vector<pair<int, int>> xy;
    int sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') sx = i, sy = j;
            else if (grid[i][j] == 'K') xy.emplace_back(i, j);
        }
    }
    xy.emplace_back(sx, sy);
    int sz = xy.size();

    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};
    vector<vector<int>> d(sz, vector<int>(sz));
    for (int i = 0; i < sz; i++) {
        auto [x, y] = xy[i];
        vector<vector<int>> dst(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        dst[x][y] = 0;
        q.emplace(x, y);
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i], ny = cy + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 'X') continue;
                if (dst[nx][ny] < 0) {
                    dst[nx][ny] = dst[cx][cy] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
        for (int j = i; j < sz; j++) {
            auto [nx, ny] = xy[j];
            d[i][j] = d[j][i] = dst[nx][ny];
        }
    }

    const int inf = 1e9;
    int ans = inf;
    vector<bool> used(sz, false);
    function<void(int, int, int)> sel = [&](int cnt, int sum, int pre) {
        if (cnt == 5) {
            ans = min(ans, sum);
            return;
        }
        for (int i = 0; i < sz - 1; i++) {
            if (used[i] || d[pre][i] < 0) continue;
            used[i] = true;
            sel(cnt + 1, sum + d[pre][i], i);
            used[i] = false;
        }
    };
    sel(0, 0, sz - 1);
    cout << (ans < inf ? ans : -1) << '\n';
}