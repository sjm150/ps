#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int n, m, wcnt;
int grid[8][8];
vector<pi> vir;
bool vst[8][8];
int minc = 64;

int dfs(int x, int y) {
    int cnt = 1;
    vst[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m &&
            grid[nx][ny] == 0 && !vst[nx][ny]) cnt += dfs(nx, ny);
    }
    return cnt;
}

void sel(int x, int y, int r) {
    if (r == 0) {
        for (int i = 0; i < n; i++) fill(vst[i], vst[i] + m, false);
        int cnt = 0;
        for (auto [vx, vy]: vir) {
            cnt += dfs(vx, vy);
        }
        minc = min(minc, cnt);
        return;
    }
    if (x == n) return;
    if (y == m) {
        sel(x + 1, 0, r);
        return;
    }
    sel(x, y + 1, r);
    if (grid[x][y] == 0) {
        grid[x][y] = 1;
        sel(x, y + 1, r - 1);
        grid[x][y] = 0;
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) wcnt++;
            else if (grid[i][j] == 2) vir.emplace_back(i, j);
        }
    }
    sel(0, 0, 3);
    cout << n * m - wcnt - 3 - minc << '\n';
}