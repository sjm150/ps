#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

#define R 10000
#define F 90000

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, m, g, r;
int land[50][50];
int gx[5], gy[5], rx[5], ry[5];
int max_flowers;

int times[50][50];

bool check_red(int time) {
    return time >= R;
}

void check_flowers() {
    for (int i = 0; i < n; i++) fill(times[i], times[i] + m, -1);
    queue<pair<int, int>> q;
    for (int i = 0; i < g; i++) {
        q.emplace(gx[i], gy[i]);
        times[gx[i]][gy[i]] = 0;
    }
    for (int i = 0; i < r; i++) {
        q.emplace(rx[i], ry[i]);
        times[rx[i]][ry[i]] = R;
    }

    int num = 0;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        int t = times[x][y];
        if (t == F) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && land[nx][ny] != 0) {
                if (times[nx][ny] < 0) {
                    q.emplace(nx, ny);
                    times[nx][ny] = t + 1;
                } else if (check_red(t) && times[nx][ny] + R == t + 1) {
                    times[nx][ny] = F;
                    num++;
                }
            }
        }
    }

    max_flowers = max(max_flowers, num);
}

void select(int x, int y, int gsel, int rsel) {
    if (gsel == g && rsel == r) {
        check_flowers();
        return;
    }
    if (x == n) return;
    int nx = x, ny = y + 1;
    if (ny == m) nx = x + 1, ny = 0;
    if (land[x][y] == 2) {
        if (gsel < g) {
            gx[gsel] = x, gy[gsel] = y;
            select(nx, ny, gsel + 1, rsel);
        }
        if (rsel < r) {
            rx[rsel] = x, ry[rsel] = y;
            select(nx, ny, gsel, rsel + 1);
        }
    }
    select(nx, ny, gsel, rsel);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> g >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> land[i][j];
        }
    }
    select(0, 0, 0, 0);
    cout << max_flowers << '\n';
}