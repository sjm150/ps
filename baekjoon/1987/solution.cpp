#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int r, c;
char grid[20][20];
bool vst[26];
int maxd;

void dfs(int d, int x, int y) {
    vst[grid[x][y] - 'A'] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < r && 0 <= ny && ny < c && !vst[grid[nx][ny] - 'A']) {
            dfs(d + 1, nx, ny);
        }
    }
    if (maxd < d) maxd = d;
    vst[grid[x][y] - 'A'] = false;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string line; cin >> line;
        for (int j = 0; j < c; j++) grid[i][j] = line[j];
    }
    dfs(1, 0, 0);
    cout << maxd << '\n';
}