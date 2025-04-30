#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (auto &s: grid) cin >> s;
    auto check = [&](int x, int y, int dx, int dy) {
        const char c[][3] = {"EI", "NS", "FT", "PJ"};
        for (int i = 0; i < 4; i++) {
            if (x < 0 || x >= n || y < 0 || y >= m || !(grid[x][y] == c[i][0] || grid[x][y] == c[i][1])) return 0;
            x += dx;
            y += dy;
        }
        return 1;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += check(i, j, 0, 1);
            ans += check(i, j, 0, -1);
            ans += check(i, j, 1, 0);
            ans += check(i, j, -1, 0);
            ans += check(i, j, 1, 1);
            ans += check(i, j, -1, -1);
            ans += check(i, j, -1, 1);
            ans += check(i, j, 1, -1);
        }
    }
    cout << ans << '\n';
}