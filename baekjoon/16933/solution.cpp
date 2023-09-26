#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, int> ti4;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int n, m, k;
char grid[1000][1000];
int dst[2][11][1000][1000];

bool oob(int x, int y) {
    return x < 0 || n <= x || y < 0 || m <= y;
}

int solve() {
    queue<ti4> q;
    dst[1][0][0][0] = 1;
    q.emplace(1, 0, 0, 0);
    while (!q.empty()) {
        auto [isday, cnt, x, y] = q.front(); q.pop();
        int d = dst[isday][cnt][x][y];
        if (x == n - 1 && y == m - 1) return dst[isday][cnt][x][y];
        int& nd = dst[1 - isday][cnt][x][y];
        if (nd == 0) {
            nd = d + 1;
            q.emplace(1 - isday, cnt, x, y);
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (oob(nx, ny)) continue;
            if (grid[nx][ny] == '0') {
                int& nd = dst[1 - isday][cnt][nx][ny];
                if (nd == 0) {
                    nd = d + 1;
                    q.emplace(1 - isday, cnt, nx, ny);
                }
            } else if (isday && cnt < k) {
                int& nd = dst[1 - isday][cnt + 1][nx][ny];
                if (nd == 0) {
                    nd = d + 1;
                    q.emplace(1 - isday, cnt + 1, nx, ny);
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