#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int grid[20][20];
int dst[20][20];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 9) {
                sx = i, sy = j;
                grid[i][j] = 0;
            }
        }
    }
    int t = 0, sz = 2, grw = 0;
    while (true) {
        queue<pi> q;
        for (int i = 0; i < n; i++) fill(dst[i], dst[i] + n, -1);
        dst[sx][sy] = 0;
        q.emplace(sx, sy);
        int mind = -1;
        int mx = n, my = n;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            int d = dst[x][y];
            if (mind >= 0) {
                if (d > mind) break;
                else if (d == mind && pi(mx, my) > pi(x, y) && grid[x][y] != 0 && grid[x][y] < sz) mx = x, my = y;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n && dst[nx][ny] < 0 && grid[nx][ny] <= sz) {
                    dst[nx][ny] = d + 1;
                    if (mind < 0 && grid[nx][ny] != 0 && grid[nx][ny] < sz) {
                        mind = d + 1;
                        mx = nx, my = ny;
                    }
                    q.emplace(nx, ny);
                }
            }
        }
        if (mx == n && my == n) break;
        t += mind;
        sx = mx, sy = my;
        grid[sx][sy] = 0;
        grw++;
        if (grw == sz) sz++, grw = 0;
    }
    cout << t << '\n';
}