#include <iostream>

using namespace std;

int n, m, k;
int grid[40][40];
int r, c;
int sticker[10][10];

int rotate(int x, int y, int d) {
    if (d == 0) {
        return sticker[x][y];
    } else if (d == 1) {
        return sticker[r - 1 - y][x];
    } else if (d == 2) {
        return sticker[r - 1 - x][c - 1 - y];
    } else {
        return sticker[y][c - 1 - x];
    }
}

bool overlaps(int x, int y, int d) {
    for (int i = 0; i < (d % 2 == 0 ? r : c); i++) {
        for (int j = 0; j < (d % 2 == 0 ? c : r); j++) {
            if (grid[x + i][y + j] == 1 && rotate(i, j, d) == 1) return true;
        }
    }
    return false;
}

bool put(int d) {
    int rr = (d % 2 == 0 ? r : c);
    int cc = (d % 2 == 0 ? c : r);
    for (int x = 0; x < n + 1 - rr; x++) {
        for (int y = 0; y < m + 1 - cc; y++) {
            if (!overlaps(x, y, d)) {
                for (int i = 0; i < rr; i++) {
                    for (int j = 0; j < cc; j++) {
                        grid[x + i][y + j] += rotate(i, j, d);
                    }
                }
                return true;
            }
        }
    }
    return false;
}

int count() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt += grid[i][j];
        }
    }
    return cnt;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> sticker[i][j];
            }
        }
        for (int d = 0; d < 4; d++) {
            if (put(d)) break;
        }
    }
    cout << count() << '\n';
}