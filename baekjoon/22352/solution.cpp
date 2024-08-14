#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> a, b;
    a = b = vector<vector<int>>(n, vector<int>(m));
    for (auto &a: a) {
        for (int &a: a) cin >> a;
    }
    for (auto &b: b) {
        for (int &b: b) cin >> b;
    }
    vector<vector<int>> grp(n, vector<int>(m, -1));
    vector<pair<int, int>> ld;
    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};
    function<void(int, int)> dfs = [&](int x, int y) {
        grp[x][y] = ld.size();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
                grp[nx][ny] >= 0 || a[x][y] != a[nx][ny]) continue;
            dfs(nx, ny);
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grp[i][j] >= 0) continue;
            dfs(i, j);
            ld.emplace_back(i, j);
        }
    }
    bool poss = true;
    vector<bool> df(ld.size());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) df[grp[i][j]] = true;
            auto &[lx, ly] = ld[grp[i][j]];
            if (b[i][j] != b[lx][ly]) {
                poss = false;
                break;
            }
        }
        if (!poss) break;
    }
    cout << (poss && accumulate(df.begin(), df.end(), 0) <= 1 ? "YES\n" : "NO\n");
}