#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int n;
int grid[100][100];
bool vst[100][100];

void init_vst() {
    for (int i = 0; i < n; i++) fill(vst[i], vst[i] + n, false);
}

bool oob(int x, int y) {
    return x < 0 || n <= x || y < 0 || n <= y;
}

void dfs(int x, int y, int h) {
    vst[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (oob(nx, ny) || grid[nx][ny] < h || vst[nx][ny]) continue;
        dfs(nx, ny, h);
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    int maxc = 0;
    for (int h = 1; h <= 100; h++) {
        int cnt = 0;
        init_vst();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vst[i][j] || grid[i][j] < h) continue;
                dfs(i, j, h);
                cnt++;
            }
        }
        if (cnt == 0) break;
        maxc = max(maxc, cnt);
    }
    cout << maxc << '\n';
}