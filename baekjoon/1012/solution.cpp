#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int m, n;
bool grid[50][50];
bool visited[50][50];

bool dfs(int x, int y) {
    if (visited[x][y] || !grid[x][y]) return false;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < m && 0 <= ny && ny < n) dfs(nx, ny);
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int k, count = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = false;
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            grid[x][y] = true;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j)) count++;
            }
        }
        cout << count << '\n';
    }
}