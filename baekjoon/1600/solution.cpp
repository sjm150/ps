#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int hdy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int hdx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int k, w, h;
int grid[200][200];
int dist[31][200][200];

int out_of_bound(int x, int y) {
    return x < 0 || h <= x || y < 0 || w <= y;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++){
            cin >> grid[i][j];
        }
    }

    queue<tuple<int, int, int>> q;
    bool reached = false;
    dist[0][0][0] = 1;
    q.emplace(0, 0, 0);
    while (!q.empty()) {
        int used, x, y;
        tie(used, x, y) = q.front();
        int d = dist[used][x][y];
        q.pop();

        if (x == h - 1 && y == w - 1) {
            cout << d - 1 << '\n';
            reached = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (out_of_bound(nx, ny)) continue;
            if (grid[nx][ny] == 1 || dist[used][nx][ny] > 0) continue;
            dist[used][nx][ny] = d + 1;
            q.emplace(used, nx, ny);
        }
        if (used < k) {
            for (int i = 0; i < 8; i++) {
                int nx = x + hdx[i];
                int ny = y + hdy[i];
                if (out_of_bound(nx, ny)) continue;
                if (grid[nx][ny] == 1 || dist[used + 1][nx][ny] > 0) continue;
                dist[used + 1][nx][ny] = d + 1;
                q.emplace(used + 1, nx, ny);
            }
        }
    }

    if (!reached) cout << "-1\n";
}