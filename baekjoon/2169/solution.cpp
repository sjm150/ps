#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &a: a) {
        for (int &a: a) cin >> a;
    }
    const int dx[] = {0, 0, 1};
    const int dy[] = {-1, 1, 0};
    const int inf = 1e9;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -inf)));
    function<int(int, int, int)> get = [&](int x, int y, int d) {
        if (x == 0 && y == 0) return a[x][y];
        int &ret = dp[x][y][d];
        if (ret > -inf) return ret;
        for (int i = 0; i < 3; i++) {
            if (dx[i] == -dx[d] && dy[i] == -dy[d]) continue;
            int px = x - dx[i];
            int py = y - dy[i];
            if (px < 0 || px >= n || py < 0 || py >= m) continue;
            ret = max(ret, a[x][y] + get(px, py, i));
        }
        return ret;
    };
    cout << get(n - 1, m - 1, 2) << '\n';
}