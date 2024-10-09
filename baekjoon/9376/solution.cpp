#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> ti;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int h, w; cin >> h >> w;
        vector<string> grid(h);
        for (auto &s: grid) cin >> s;

        vector<vector<vector<int>>> dst;
        priority_queue<ti, vector<ti>, greater<ti>> pq;
        auto push = [&](int i, int j, int d) {
            if (i < 0 || i >= h || j < 0 || j >= w || grid[i][j] == '*' || dst.back()[i][j] >= 0) return;
            dst.back()[i][j] = d + (grid[i][j] == '#');
            pq.emplace(dst.back()[i][j], i, j);
        };
        auto bfs = [&]() {
            while (!pq.empty()) {
                auto [d, x, y] = pq.top(); pq.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    push(nx, ny, d);
                }
            }
        };

        dst.emplace_back(h, vector<int>(w, -1));
        for (int j = 0; j < w; j++) {
            push(0, j, 0);
            push(h - 1, j, 0);
        }
        for (int i = 1; i < h - 1; i++) {
            push(i, 0, 0);
            push(i, w - 1, 0);
        }
        bfs();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == '$') {
                    dst.emplace_back(h, vector<int>(w, -1));
                    push(i, j, 0);
                    bfs();
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == '$') ans += dst[0][i][j];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (dst[0][i][j] < 0 || dst[1][i][j] < 0 || dst[2][i][j] < 0) continue;
                ans = min(ans, dst[0][i][j] + dst[1][i][j] + dst[2][i][j] - (grid[i][j] == '#' ? 2 : 0));
            }
        }
        cout << ans << '\n';
    }
}