#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int moves[300][300];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int l, start_x, start_y, target_x, target_y;
        cin >> l >> start_x >> start_y >> target_x >> target_y;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                moves[i][j] = -1;
            }
        }

        queue<pair<int, int>> q;
        q.emplace(start_x, start_y);
        moves[start_x][start_y] = 0;
        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            int m = moves[x][y];
            q.pop();

            if (x == target_x && y == target_y) {
                cout << m << '\n';
                break;
            }

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < l && 0 <= ny && ny < l && moves[nx][ny] < 0) {
                    moves[nx][ny] = m + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}