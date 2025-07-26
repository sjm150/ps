#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int tc = 1;; tc++) {
        int r, c;
        cin >> r >> c;
        if (r == 0) break;
        vector<string> grid(r);
        for (auto &g: grid) cin >> g;
        string s;
        cin >> s;

        int x = 0, y = 0, cnt = 0;
        vector<vector<bool>> tar(r, vector<bool>(c, false));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char &c = grid[i][j];
                if (c == '+') {
                    tar[i][j] = true;
                    cnt++;
                    c = '.';
                } else if (c == 'B') {
                    tar[i][j] = true;
                    c = 'b';
                } else if (c == 'W') {
                    tar[i][j] = true;
                    cnt++;
                    c = 'w';
                }
                if (c == 'w') {
                    x = i, y = j;
                    c = '.';
                }
            }
        }

        auto dir = [&](char c) {
            if (c == 'U') return make_pair(-1, 0);
            else if (c == 'D') return make_pair(1, 0);
            else if (c == 'L') return make_pair(0, -1);
            else return make_pair(0, 1);
        };
        for (char c: s) {
            auto [dx, dy] = dir(c);
            int nx = x + dx, ny = y + dy;
            if (grid[nx][ny] == '#') continue;
            if (grid[nx][ny] == 'b') {
                int nnx = nx + dx, nny = ny + dy;
                if (grid[nnx][nny] == '.') {
                    if (tar[nx][ny]) cnt++;
                    if (tar[nnx][nny]) cnt--;
                    swap(grid[nx][ny], grid[nnx][nny]);
                    x = nx, y = ny;
                    if (cnt == 0) break;
                }
            } else {
                x = nx, y = ny;
            }
        }

        grid[x][y] = 'w';
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!tar[i][j]) continue;
                if (grid[i][j] == 'b') grid[i][j] = 'B';
                else if (grid[i][j] == 'w') grid[i][j] = 'W';
                else grid[i][j] = '+';
            }
        }

        cout << "Game " << tc << ": " << (cnt == 0 ? "complete\n" : "incomplete\n");
        for (auto &g: grid) cout << g << '\n';
    }
}