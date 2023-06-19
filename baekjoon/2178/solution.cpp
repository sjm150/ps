#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int n, m;
bool pass[100][100];
bool visited[100][100];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            pass[i][j] = (line[j] == '1') ? 1 : 0;
        }
    }

    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (x == n - 1 && y == m - 1) {
            cout << dist << '\n';
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m
                && pass[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, dist + 1});
            }
        }
    }
}