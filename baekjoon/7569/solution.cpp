#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {-1, 0, 1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int m, n, h;
int status[100][100][100];
int days[100][100][100];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int curr = 0, target;
    cin >> m >> n >> h;
    target = m * n * h;
    queue<tuple<int, int, int>> q;

    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int num;
                cin >> num;
                days[k][i][j] = -1;
                status[k][i][j] = num;
                if (num < 0) {
                    target--;
                } else if (num > 0) {
                    curr++;
                    q.emplace(k, i, j);
                    days[k][i][j] = 0;
                }
            }
        }
    }

    int min_days = 0;
    while (!q.empty()) {
        int x, y, z;
        tie(z, x, y) = q.front();
        int d = days[z][x][y];
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && 0 <= nz && nz < h
                && status[nz][nx][ny] == 0 && days[nz][nx][ny] < 0) {
                q.emplace(nz, nx, ny);
                days[nz][nx][ny] = d + 1;
                curr++;
                min_days = max(min_days, days[nz][nx][ny]);
            }
        }
    }
    
    if (target == curr) cout << min_days << '\n';
    else cout << "-1\n";
}