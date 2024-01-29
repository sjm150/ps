#include <bits/stdc++.h>
using namespace std;

const int dy[6] = {-1, -1, 0, 0, 1, 1};
const int dx[2][6] = {{0, 1, -1, 1, 0, 1}, {-1, 0, -1, 1, -1, 0}};

int h, w;
vector<vector<bool>> grid, vst;

bool oob(int y, int x) {
    return y < 0 || h <= y || x < 0 || w <= x;
}

int dfs(int y, int x) {
    int ret = 0;
    vst[y][x] = true;
    for (int i = 0; i < 6; i++) {
        int ny = y + dy[i];
        int nx = x + dx[y & 1][i];
        if (oob(ny, nx)) {
            ret--;
            continue;
        }
        if (vst[ny][nx]) continue;
        if (grid[ny][nx]) ret++;
        else ret += dfs(ny, nx);
    }
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> w >> h;
    grid.resize(h, vector<bool>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int b; cin >> b;
            grid[i][j] = b;
        }
    }

    vst.resize(h, vector<bool>(w, false));
    int sum = (w + h) * 4 - 2;
    for (int i = 0; i < h; i++) {
        if (!vst[i][0] && !grid[i][0]) sum += dfs(i, 0);
        if (!vst[i][w - 1] && !grid[i][w - 1]) sum += dfs(i, w - 1);
    }
    for (int i = 0; i < w; i++) {
        if (!vst[0][i] && !grid[0][i]) sum += dfs(0, i);
        if (!vst[h - 1][i] && !grid[h - 1][i]) sum += dfs(h - 1, i);
    }

    cout << sum << '\n';
}