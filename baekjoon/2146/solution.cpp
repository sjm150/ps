#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n;
int map[100][100];
int vst[100][100];
int dst[100][100];

void dfs(int x, int y, int v, queue<pair<int, int>>& q) {
    vst[x][y] = v;
    dst[x][y] = 0;
    bool is_border = false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if (map[nx][ny] == 0) is_border = true;
            else if (vst[nx][ny] < 0) dfs(nx, ny, v, q);
        }
    }

    if (is_border) q.emplace(x, y);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            vst[i][j] = dst[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    int vidx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vst[i][j] < 0 && map[i][j] == 1) dfs(i, j, vidx++, q);
        }
    }

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        int v = vst[x][y];
        int d = dst[x][y];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n
                && map[nx][ny] == 0) {
                if (dst[nx][ny] == -1) {
                    vst[nx][ny] = v;
                    dst[nx][ny] = d + 1;
                    q.emplace(nx, ny);
                } else if (vst[nx][ny] != -1 && v != vst[nx][ny]) {
                    cout << d + dst[nx][ny] << '\n';
                    return 0;
                }
            }
        }
    }
}