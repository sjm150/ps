#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int n, m;
int map[300][300];
int adj[300][300];
bool vst[300][300];

void dfs(int x, int y) {
    vst[x][y] = true;
    adj[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (map[nx][ny] == 0) adj[x][y]++;
            else if (!vst[nx][ny]) dfs(nx, ny);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int year = 0;
    while (true) {
        int count = 0;
        for (int i = 0; i < n; i++) fill(vst[i], vst[i] + m, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] > 0 && !vst[i][j]) {
                    count++;
                    dfs(i, j);
                }
            }
        }
        if (count == 0) {
            cout << "0\n";
            break;
        }
        if (count >= 2) {
            cout << year << '\n';
            break;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] > 0) {
                    map[i][j] = max(map[i][j] - adj[i][j], 0);
                }
            }
        }
        year++;
    }
}