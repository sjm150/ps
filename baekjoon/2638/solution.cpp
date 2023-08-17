#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int n, m;
int grid[100][100];
int cont[100][100];

void dfs(int x, int y) {
    cont[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
        if (grid[nx][ny] == 1) cont[nx][ny]++;
        else if (cont[nx][ny] == 0) dfs(nx, ny);
    }
}

void melt() {
    for (int i = 0; i < n; i++) fill(cont[i], cont[i] + m, 0);
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cont[i][j] >= 2) grid[i][j]--;
        }
    }
}

bool done() {
    bool ret = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) ret = false;
        }
    }
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int t = 0;
    while (!done()) {
        t++;
        melt();
    }
    cout << t << '\n';
}