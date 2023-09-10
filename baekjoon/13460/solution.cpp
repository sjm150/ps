#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int, int> ti5;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int n, m;
char grid[10][10];
ti3 next_coord[10][10][4];

void init_inner(int dir, int x, int y, int& nx, int& ny, int& p, int& b) {
    if (grid[x][y] == '#') {
        nx = ny = -1;
    } else {
        if (grid[x][y] == 'O') nx = x, ny = y, p = 0, b = 0;
        else if (nx == -1) nx = x, ny = y, p = 0, b = 1;
        next_coord[x][y][dir] = {nx, ny, b * p};
        p++;
    }
}

void init_nc() {
    int dir = 0;
    int nx = -1, ny = -1, p = 0, b = 1;
    for (int i = 1; i < n - 1; i++) {
        dir = 0;
        for (int j = 0; j < m; j++) init_inner(dir, i, j, nx, ny, p, b);
        dir = 1;
        for (int j = m - 1; j >= 0; j--) init_inner(dir, i, j, nx, ny, p, b);
    }
    for (int j = 1; j < m - 1; j++) {
        dir = 2;
        for (int i = 0; i < n; i++) init_inner(dir, i, j, nx, ny, p, b);
        dir = 3;
        for (int i = n - 1; i >= 0; i--) init_inner(dir, i, j, nx, ny, p, b);
    }
}

int rev(int d) {
    if (d < 2) return 1 - d;
    else return 5 - d;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int ox, oy, rx, ry, bx, by;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'O') ox = i, oy = j;
            else if (grid[i][j] == 'R') rx = i, ry = j;
            else if (grid[i][j] == 'B') bx = i, by = j;
        }
    }
    init_nc();

    queue<ti5> q;
    q.emplace(0, rx, ry, bx, by);
    int minc = -1;
    while (!q.empty()) {
        auto [cnt, rx, ry, bx, by] = q.front(); q.pop();
        if (bx == ox && by == oy) {
            continue;
        } else if (rx == ox && ry == oy) {
            minc = cnt;
            break;
        }
        if (cnt < 10) {
            for (int d = 0; d < 4; d++) {
                auto [nrx, nry, rp] = next_coord[rx][ry][d];
                auto [nbx, nby, bp] = next_coord[bx][by][d];
                if (nrx == nbx && nry == nby) {
                    if (rp < bp) nbx += dx[rev(d)], nby += dy[rev(d)];
                    else if (rp > bp) nrx += dx[rev(d)], nry += dy[rev(d)];
                }
                q.emplace(cnt + 1, nrx, nry, nbx, nby);
            }
        }
    }
    cout << minc << '\n';
}