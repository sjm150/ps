#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, a, b, k; cin >> n >> m >> a >> b >> k;
    n -= a - 1, m -= b - 1;
    vector<vector<bool>> blk(n, vector<bool>(m, false));
    while (k--) {
        int x, y; cin >> x >> y;
        x--, y--;
        for (int i = min(x, n - 1); x - i + 1 <= a; i--) {
            if (i < 0) break;
            for (int j = min(y, m - 1); y - j + 1 <= b; j--) {
                if (j < 0) break;
                blk[i][j] = true;
            }
        }
    }

    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};

    int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;
    vector<vector<int>> dst(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    dst[sx][sy] = 0;
    q.emplace(sx, sy);
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || n <= nx || ny < 0 || m <= ny || dst[nx][ny] >= 0 || blk[nx][ny]) continue;
            dst[nx][ny] = dst[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
    cout << dst[ex][ey] << '\n';
}