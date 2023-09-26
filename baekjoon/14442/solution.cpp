#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int n, m, k;
char grid[1000][1000];
int dst[11][1000][1000];

bool oob(int x, int y) {
    return x < 0 || n <= x || y < 0 || m <= y;
}

int solve() {
    queue<ti> q;
    dst[0][0][0] = 1;
    q.emplace(0, 0, 0);
    while (!q.empty()) {
        auto [cnt, x, y] = q.front(); q.pop();
        if (x == n - 1 && y == m - 1) return dst[cnt][x][y];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (oob(nx, ny)) continue;
            if (grid[nx][ny] == '0') {
                if (dst[cnt][nx][ny] == 0) {
                    dst[cnt][nx][ny] = dst[cnt][x][y] + 1;
                    q.emplace(cnt, nx, ny);
                }
            } else {
                if (cnt < k && dst[cnt + 1][nx][ny] == 0) {
                    dst[cnt + 1][nx][ny] = dst[cnt][x][y] + 1;
                    q.emplace(cnt + 1, nx, ny);
                }
            }
        }
    }
    return -1;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    cout << solve() << '\n';
}