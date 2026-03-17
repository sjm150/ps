#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &a: a) {
        for (int &a: a) cin >> a;
    }
    int ans = 200;
    for (int i = 0; i <= 200; i++) {
        int l = i, r = 400;
        while (l < r) {
            int m = (l + r) / 2;
            vector<vector<bool>> vst(n, vector<bool>(n, false));
            function<void(int, int)> dfs = [&](int x, int y) {
                vst[x][y] = true;
                for (auto [dx, dy]: {make_pair(-1, 0), {1, 0}, {0, -1}, {0, 1}}) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || vst[nx][ny]) continue;
                    if (i <= a[nx][ny] && a[nx][ny] <= m) dfs(nx, ny);
                }
            };
            if (i <= a[0][0] && a[0][0] <= m) dfs(0, 0);
            if (vst[n - 1][n - 1]) r = m;
            else l = m + 1;
        }
        ans = min(ans, r - i);
    }
    cout << ans << '\n';
}