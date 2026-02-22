#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, l, r;
    cin >> n >> l >> r;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &a: a) {
        for (int &a: a) cin >> a;
    }

    int ans = 0;
    for (;; ans++) {
        vector<vector<int>> grp(n, vector<int>(n, -1));
        function<void(int, int, int)> dfs = [&](int x, int y, int g) {
            grp[x][y] = g;
            for (auto [dx, dy]: {make_pair(-1, 0), {1, 0}, {0, -1}, {0, 1}}) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                int d = abs(a[x][y] - a[nx][ny]);
                if (l <= d && d <= r && grp[nx][ny] < 0) dfs(nx, ny, g);
            }
        };

        int g = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grp[i][j] < 0) dfs(i, j, g++);
            }
        }

        vector<int> sum(g), cnt(g);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) sum[grp[i][j]] += a[i][j], cnt[grp[i][j]]++;
        }

        auto b = a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) b[i][j] = sum[grp[i][j]] / cnt[grp[i][j]];
        }

        if (a == b) break;
        swap(a, b);
    }

    cout << ans << '\n';
}