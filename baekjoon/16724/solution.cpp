#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int grid[1000][1000];
int vst[1000][1000];

int dir(char c) {
    if (c == 'U') return 0;
    else if (c == 'D') return 1;
    else if (c == 'L') return 2;
    else return 3;
}

bool dfs(int x, int y, int v) {
    vst[x][y] = v;
    int nx = x + dx[grid[x][y]];
    int ny = y + dy[grid[x][y]];
    if (vst[nx][ny] > 0) {
        if (vst[nx][ny] == v) return true;
        else return false;
    } else {
        return dfs(nx, ny, v);
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string line; cin >> line;
        for (int j = 0; j < m; j++) grid[i][j] = dir(line[j]);
    }
    int v = 1;
    int ccnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vst[i][j] == 0 && dfs(i, j, v++)) ccnt++;
        }
    }
    cout << ccnt << '\n';
}