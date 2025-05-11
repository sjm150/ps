#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    const int fl = 1, fd = 2, fr = 4, fu = 8;
    const tuple<int, int, int> delta[] = {{0, -1, fl}, {1, 0, fd}, {0, 1, fr}, {-1, 0, fu}};
    int h, w;
    for (;;) {
        cin >> h >> w;
        if (h == 0) break;

        vector<vector<int>> grid(h, vector<int>(w));
        for (auto &g: grid) {
            for (int &g: g) {
                char c; cin >> c;
                g = c > '9' ? c - 'A' + 10 : c - '0';
            }
        }

        const pi undef = {-1, -1};
        pi s = undef, e = undef;
        auto assgn = [&](int x, int y) {
            if (s == undef) s = {x, y};
            else e = {x, y};
        };
        for (int i = 0; i < h; i++) {
            if ((grid[i][0] & fl) == 0) assgn(i, 0);
            if ((grid[i][w - 1] & fr) == 0) assgn(i, w - 1);
        }
        for (int j = 0; j < w; j++) {
            if ((grid[0][j] & fu) == 0) assgn(0, j);
            if ((grid[h - 1][j] & fd) == 0) assgn(h - 1, j);
        }
        assert(s != undef);
        assert(e != undef);

        bool cyc = false;
        vector<vector<bool>> vst(h, vector<bool>(w, false));
        function<void(int, int, int, int)> dfs = [&](int px, int py, int x, int y) {
            vst[x][y] = true;
            for (auto [dx, dy, f]: delta) {
                int nx = x + dx, ny = y + dy;
                if (nx == px && ny == py) continue;
                if (grid[x][y] & f) continue;
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (vst[nx][ny]) cyc = true;
                else dfs(x, y, nx, ny);
            }
        };
        dfs(-1, -1, s.first, s.second);

        int cnt = 0;
        for (auto &v: vst) cnt += accumulate(v.begin(), v.end(), 0);

        if (!vst[e.first][e.second]) cout << "NO SOLUTION\n";
        else if (cnt < w * h) cout << "UNREACHABLE CELL\n";
        else if (cyc) cout << "MULTIPLE PATHS\n";
        else cout << "MAZE OK\n";
    }
}