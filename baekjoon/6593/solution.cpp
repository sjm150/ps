#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;

const int dz[6] = {-1, 1, 0, 0, 0, 0};
const int dx[6] = {0, 0, -1, 1, 0, 0};
const int dy[6] = {0, 0, 0, 0, -1, 1};

int l, r, c;
char cube[30][30][30];
int dst[30][30][30];

bool oob(int z, int x, int y) {
    return z < 0 || l <= z || x < 0 || r <= x || y < 0 || c <= y;
}

int solve() {
    int sz, sx, sy;
    int ez, ex, ey;
    for (int h = 0; h < l; h++) {
        for (int i = 0; i < r; i++) {
            fill(dst[h][i], dst[h][i] + c, -1);
            for (int j = 0; j < c; j++) {
                cin >> cube[h][i][j];
                if (cube[h][i][j] == 'S') sz = h, sx = i, sy = j;
                else if (cube[h][i][j] == 'E') ez = h, ex = i, ey = j;
            }
        }
    }
    queue<ti> q;
    dst[sz][sx][sy] = 0;
    q.emplace(sz, sx, sy);
    while (!q.empty()) {
        auto [z, x, y] = q.front(); q.pop();
        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (oob(nz, nx, ny) || cube[nz][nx][ny] == '#' || dst[nz][nx][ny] >= 0) continue;
            dst[nz][nx][ny] = dst[z][x][y] + 1;
            q.emplace(nz, nx, ny);
        }
    }
    return dst[ez][ex][ey];
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    while (true) {
        cin >> l >> r >> c;
        if (l == 0) break;
        int d = solve();
        if (d > 0) cout << "Escaped in " << d << " minute(s).\n";
        else cout << "Trapped!\n";
    }
}