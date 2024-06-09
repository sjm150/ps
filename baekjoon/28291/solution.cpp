#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int w, h, n; cin >> w >> h >> n;
    vector<vector<bool>> blk(h, vector<bool>(w, true));
    vector<vector<int>> dst(h, vector<int>(w, -1));
    queue<pair<int, int>> q;
    set<pair<int, int>> lmp;
    while (n--) {
        string s; cin >> s;
        int x, y; cin >> x >> y;
        if (s[9] == 'b') {
            dst[y][x] = 0;
            q.emplace(y, x);
        } else if (s[9] == 'd') {
            blk[y][x] = false;
        } else {
            lmp.emplace(y, x);
        }
    }

    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
            if (dst[nx][ny] >= 0) continue;

            auto it = lmp.find(make_pair(nx, ny));
            if (it != lmp.end()) {
                dst[nx][ny] = dst[x][y] + 1;
                continue;
            }

            if (blk[nx][ny]) continue;
            dst[nx][ny] = dst[x][y] + 1;
            q.emplace(nx, ny);
        }
    }

    bool suc = true;
    for (auto &[x, y]: lmp) {
        if (dst[x][y] < 0 || dst[x][y] > 15) {
            suc = false;
            break;
        }
    }
    cout << (suc ? "success\n" : "failed\n");
}