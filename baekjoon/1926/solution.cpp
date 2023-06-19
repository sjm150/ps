#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int n, m;
int grid[500][500];
bool visited[500][500];

int dfs_size(int x, int y) {
    if (visited[x][y]) return 0;
    visited[x][y] = true;
    if (grid[x][y] == 0) return 0;

    int size = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            size += dfs_size(nx, ny);
        }
    }

    return size;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int count = 0, max_size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                int size = dfs_size(i, j);
                if (size > 0) count++;
                max_size = max(max_size, size);
            }
        }
    }

    cout << count << '\n' << max_size << '\n';
}