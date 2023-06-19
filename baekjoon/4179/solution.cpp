#include <iostream>
#include <queue>

#define W -1
#define S 0
#define J 1
#define F 2

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int r, c;
int status[1000][1000];
int times[1000][1000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    queue<pair<int, int>> q;
    int jx, jy;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < c; j++) {
            switch (line[j]) {
                case '#':
                    status[i][j] = W;
                    break;
                case '.':
                    status[i][j] = S;
                    break;
                case 'J':
                    status[i][j] = J;
                    jx = i;
                    jy = j;
                    times[i][j] = 0;
                    break;
                case 'F':
                    status[i][j] = F;
                    q.emplace(i, j);
                    times[i][j] = 0;
                    break;
                default: break;
            }
        }
    }
    q.emplace(jx, jy);

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int s = status[x][y];
        int t = times[x][y];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || r <= nx || ny < 0 || c <= ny) {
                if (s == J) {
                    cout << t + 1 << '\n';
                    return 0;
                }
            } else if (status[nx][ny] == S) {
                status[nx][ny] = s;
                times[nx][ny] = t + 1;
                q.emplace(nx, ny);
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}