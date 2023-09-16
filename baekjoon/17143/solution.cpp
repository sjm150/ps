#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef struct Shark {
    int speed, dir, size;
} shark_t;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int r, c;
vector<shark_t> sharks;
int grid[2][101][101];
int cur = 0, nxt = 1;

pi end(int x, int y, int d) {
    if (d == 0) return {0, y};
    else if (d == 1) return {r - 1, y};
    else if (d == 2) return {x, c - 1};
    else return {x, 0};
}

int rev(int d) {
    if (d <= 1) return 1 - d;
    else return 5 - d;
}

void calc_pos(int x, int y) {
    int idx = grid[cur][x][y];
    auto [s, d, z] = sharks[idx];
    auto [ex, ey] = end(x, y, d);
    int rem = abs(ex - x) + abs(ey - y);
    while (rem < s) {
        s -= rem;
        x = ex, y = ey;
        d = rev(d);
        tie(ex, ey) = end(x, y, d);
        rem = abs(ex - x) + abs(ey - y);
    }
    sharks[idx].dir = d;
    int nx = x + s * dx[d];
    int ny = y + s * dy[d];
    if (grid[nxt][nx][ny] == 0 || sharks[grid[nxt][nx][ny]].size < z) {
        grid[nxt][nx][ny] = idx;
    }
}

void swap() {
    cur = 1 - cur;
    nxt = 1 - nxt;
}

void run() {
    for (int i = 0; i < r; i++) fill(grid[nxt][i], grid[nxt][i] + c, 0);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[cur][i][j] > 0) calc_pos(i, j);
        }
    }
    swap();
}

int fish(int idx) {
    int size = 0;
    for (int i = 0; i < r; i++) {
        if (grid[cur][i][idx] > 0) {
            size = sharks[grid[cur][i][idx]].size;
            grid[cur][i][idx] = 0;
            break;
        }
    }
    return size;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m; cin >> r >> c >> m;
    sharks = vector<shark_t>(m + 1);
    for (int i = 1; i <= m; i++) {
        int x, y, s, d, z;
        cin >> x >> y >> s >> d >> z;
        d--;
        if (d <= 1) s %= 2 * (r - 1);
        else s %= 2 * (c - 1);
        sharks[i] = {s, d, z};
        grid[cur][x - 1][y - 1] = i;
    }
    int sum = 0;
    for (int j = 0; j < c; j++) {
        sum += fish(j);
        run();
    }
    cout << sum << '\n';
}