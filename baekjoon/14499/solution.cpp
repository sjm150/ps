#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

int up, down, north, south, west, east;
int n, m;
int grid[20][20];

void roll_common(int& up_read, int& up_write) {
    int prev_up = up;
    up = up_read;
    up_read = down;
    down = up_write;
    up_write = prev_up;
}

void roll(int dir) {
    switch (dir) {
        case 1: roll_common(west, east); break;
        case 2: roll_common(east, west); break;
        case 3: roll_common(south, north); break;
        case 4: roll_common(north, south); break;
    }
}

void copy_down(int x, int y) {
    if (grid[x][y]) {
        down = grid[x][y];
        grid[x][y] = 0;
    } else {
        grid[x][y] = down;
    }
}

bool oob(int x, int y) {
    return x < 0 || n <= x || y < 0 || m <= y;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int x, y, k; cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> grid[i][j];
    while (k--) {
        int d; cin >> d;
        int nx = x + dx[d - 1];
        int ny = y + dy[d - 1];
        if (oob(nx, ny)) continue;
        roll(d);
        x = nx, y = ny;
        copy_down(x, y);
        cout << up << '\n';
    }
}