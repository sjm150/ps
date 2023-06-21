#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m;
int mat[1000][1000];
int dist[1000][1000];
int dist1[1000][1000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            mat[i][j] = line[j] - '0';
            dist[i][j] = dist1[i][j] = -1;
        }
    }

    queue<tuple<int, int, bool>> q;
    q.emplace(0, 0, false);
    dist[0][0] = dist1[0][0] = 1;
    bool reached = false;
    while (!q.empty()) {
        int y, x;
        bool breaked;
        tie(y, x, breaked) = q.front();
        q.pop();

        if (y == n - 1 && x == m - 1) {
            cout << (breaked ? dist1[y][x] : dist[y][x]) << '\n';
            reached = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                if (breaked) {
                    if (dist1[ny][nx] == -1 && mat[ny][nx] == 0) {
                        dist1[ny][nx] = dist1[y][x] + 1;
                        q.emplace(ny, nx, true);
                    }
                } else {
                    if (mat[ny][nx] == 0 && dist[ny][nx] == -1) {
                        dist[ny][nx] = dist[y][x] + 1;
                        q.emplace(ny, nx, false);
                    } else if (mat[ny][nx] == 1 && dist1[ny][nx] == -1) {
                        dist1[ny][nx] = dist[y][x] + 1;
                        q.emplace(ny, nx, true);
                    }
                }
            }
        }
    }

    if (!reached) cout << "-1\n";
}