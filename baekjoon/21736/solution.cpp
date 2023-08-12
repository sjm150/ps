#include <iostream>
#include <queue>
using namespace std;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

char cmps[600][600];
bool vst[600][600];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int x0 = 0, y0 = 0;
    for (int i = 0; i < n; i++) {
        string line; cin >> line;
        for (int j = 0; j < m; j++) {
            cmps[i][j] = line[j];
            if (cmps[i][j] == 'I') x0 = i, y0 = j;
        }
    }
    queue<pair<int, int>> q;
    vst[x0][y0] = true;
    q.emplace(x0, y0);
    int cnt = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (cmps[x][y] == 'P') cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m &&
                cmps[nx][ny] != 'X' && !vst[nx][ny]) {
                vst[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
    if (cnt > 0) cout << cnt << '\n';
    else cout << "TT\n";
}