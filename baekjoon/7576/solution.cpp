#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int m, n;
int status[1000][1000];
int days[1000][1000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int curr = 0, target;
    cin >> m >> n;
    target = m * n;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            days[i][j] = -1;
            status[i][j] = num;
            if (num < 0) {
                target--;
            } else if (num > 0) {
                curr++;
                q.emplace(i, j);
                days[i][j] = 0;
            }
        }
    }

    int min_days = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int d = days[x][y];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m &&
                status[nx][ny] == 0 && days[nx][ny] < 0) {
                q.emplace(nx, ny);
                days[nx][ny] = d + 1;
                curr++;
                min_days = max(min_days, days[nx][ny]);
            }
        }
    }

    if (target == curr) cout << min_days << '\n';
    else cout << "-1\n";
}