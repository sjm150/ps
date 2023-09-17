#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int n = 12, m = 6;

char grid[n][m];
int vst[n][m];

bool oob(int x, int y) {
    return x < 0 || n <= x || y < 0 || m <= y;
}

int dfs(int x, int y, char c, int v) {
    vst[x][y] = v;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (oob(nx, ny) || vst[nx][ny] || grid[nx][ny] != c) continue;
        cnt += dfs(nx, ny, c, v);
    }
    return cnt;
}

bool blow() {
    for (int i = 0; i < n; i++) fill(vst[i], vst[i] + m, 0);
    vector<int> sz;
    sz.push_back(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vst[i][j] == 0 && grid[i][j] != '.') {
                sz.push_back(dfs(i, j, grid[i][j], sz.size()));
            }
        }
    }
    bool blown = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sz[vst[i][j]] >= 4) {
                grid[i][j] = '.';
                blown = true;
            }
        }
    }
    return blown;
}

void drop() {
    for (int j = 0; j < m; j++) {
        int bot = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (grid[i][j] == '.') {
                if (bot < 0) bot = i;
            } else {
                if (bot >= 0) {
                    grid[bot][j] = grid[i][j];
                    grid[i][j] = '.';
                    bot--;
                }
            }
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    while (blow()) {
        drop();
        cnt++;
    }
    cout << cnt << '\n';
}