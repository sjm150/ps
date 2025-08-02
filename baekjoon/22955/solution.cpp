#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef tuple<int, int, int> ti;
    const int inf = 1e9;
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &g: grid) cin >> g;

    int sx = -1, sy = -1, ex = -1, ey = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'C') sx = i, sy = j;
            else if (grid[i][j] == 'E') ex = i, ey = j;
        }
    }

    vector<vector<int>> dn(n, vector<int>(m));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            dn[i][j] = (grid[i][j] == 'X' ? dn[i + 1][j] + 1 : 0);
        }
    }

    vector<vector<int>> dst(n, vector<int>(m, inf));
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    auto push = [&](int d, int x, int y) {
        if (grid[x][y] != 'D' && dst[x][y] > d) {
            dst[x][y] = d;
            pq.emplace(d, x, y);
        }
    };
    push(0, sx, sy);
    while (!pq.empty()) {
        auto [d, x, y] = pq.top();
        pq.pop();
        if (dst[x][y] < d) continue;
        char c = grid[x][y];
        if (c == 'X') {
            push(d + 10, x + dn[x][y], y);
            continue;
        }
        if (c == 'L' && x > 0) push(d + 5, x - 1, y);
        if (x < n - 1 && grid[x + 1][y] == 'L') push(d + 5, x + 1, y);
        if (y > 0) push(d + 1, x, y - 1);
        if (y < m - 1) push(d + 1, x, y + 1);
    }

    if (dst[ex][ey] < inf) cout << dst[ex][ey] << '\n';
    else cout << "dodo sad\n";
}