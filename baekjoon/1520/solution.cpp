#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int m, n;
int grid[500][500];
int cnt[500][500];

bool oob(int x, int y) {
    return x < 0 || m <= x || y < 0 || n <= y;
}

int getcnt(int x, int y) {
    int& cache = cnt[x][y];
    if (cache >= 0) return cache;
    cache = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (oob(nx, ny) || grid[nx][ny] <= grid[x][y]) continue;
        cache += getcnt(nx, ny);
    }
    return cache;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> grid[i][j];
        fill(cnt[i], cnt[i] + n, -1);
    }
    cnt[0][0] = 1;
    cout << getcnt(m - 1, n - 1) << '\n';
}