#include <iostream>
#include <queue>
using namespace std;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int map[1000][1000];
int dst[1000][1000];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int tx = 0, ty = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] != 0) dst[i][j] = -1;
            if (map[i][j] == 2) tx = i, ty = j;
        }
    }
    queue<pair<int, int>> q;
    dst[tx][ty] = 0;
    q.emplace(tx, ty);
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m
                && map[nx][ny] != 0 && dst[nx][ny] < 0) {
                dst[nx][ny] = dst[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << dst[i][j] << ' ';
        cout << '\n';
    }
}