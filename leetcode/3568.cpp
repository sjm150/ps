class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size(), m = classroom[0].size(), lc = 0, sx = -1, sy = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char &c = classroom[i][j];
                if (c == 'L') c = '0' + lc++;
                else if (c == 'S') sx = i, sy = j;
            }
        }

        int mx = 1 << lc;
        auto idx = [&](int e, int b, int x, int y) { return ((e * mx + b) * n + x) * m + y; };
        auto state = [&](int i) {
            int y = i % m;
            i /= m;
            int x = i % n;
            i /= n;
            int b = i % mx, e = i / mx;
            return make_tuple(e, b, x, y);
        };

        vector<int> dst(idx(energy, mx - 1, n - 1, m - 1) + 1, 1e9);
        queue<int> q;
        auto push = [&](int e, int b, int x, int y, int d) {
            int i = idx(e, b, x, y);
            if (dst[i] > d) {
                dst[i] = d;
                q.push(i);
            }
        };

        push(energy, 0, sx, sy, 0);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            auto [e, b, x, y] = state(i);
            if (!e) continue;
            int d = dst[i];
            for (auto [dx, dy]: {make_pair(-1, 0), {1, 0}, {0, -1}, {0, 1}}) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                char c = classroom[nx][ny];
                if (c == 'X') continue;
                else if ('0' <= c && c <= '9') push(e - 1, b | (1 << (c - '0')), nx, ny, d + 1);
                else if (c == 'R') push(energy, b, nx, ny, d + 1);
                else push(e - 1, b, nx, ny, d + 1);
            }
        }

        int mn = 1e9;
        for (int e = 0; e <= energy; e++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mn = min(mn, dst[idx(e, mx - 1, i, j)]);
                }
            }
        }
        return mn < 1e9 ? mn : -1;
    }
};