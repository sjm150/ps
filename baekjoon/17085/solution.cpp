#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    auto oob = [&](int x, int y) {
        return x < 0 || n <= x || y < 0 || m <= y;
    };

    int ans = 0;
    function<void(int, int)> sel = [&](int t, int cur) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int k = 0;
                for (;; k++) {
                    bool poss = true;
                    for (int d = 0; d < 4; d++) {
                        if (oob(i + k * dx[d], j + k * dy[d]) || grid[i + k * dx[d]][j + k * dy[d]] != '#') {
                            poss = false;
                            break;
                        }
                    }
                    if (!poss) break;
                    for (int d = 0; d < 4; d++) grid[i + k * dx[d]][j + k * dy[d]] = '*';
                    if (t) sel(t - 1, cur * (1 + 4 * k));
                    else ans = max(ans, cur * (1 + 4 * k));
                }
                for (int kk = 0; kk < k; kk++) {
                    for (int d = 0; d < 4; d++) grid[i + kk * dx[d]][j + kk * dy[d]] = '#';
                }
            }
        }
    };

    sel(1, 1);
    cout << ans << '\n';
}