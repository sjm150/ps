#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef tuple<int, int, int, int> ti4;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &g: grid) {
        for (int &g: g) cin >> g;
    }

    auto find = [&]() -> ti4 {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (grid[i][j] == grid[i][j + 1]) return {i, j, i, j + 1};
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == grid[i + 1][j]) return {i, j, i + 1, j};
            }
        }
        return {-1, -1, -1, -1};
    };

    auto solve = [&]() -> vector<ti4> {
        vector<ti4> ans;
        auto [a, b, x, y] = find();
        if (a < 0) return ans;

        vector<vector<bool>> used(n, vector<bool>(m, false));
        vector<vector<pair<int, int>>> cand(2);
        auto use = [&](int x, int y) {
            const pair<int, int> dlt[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
            for (auto [dx, dy]: dlt) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || used[nx][ny]) continue;
                used[nx][ny] = true;
                cand[grid[nx][ny]].emplace_back(nx, ny);
            }
            return make_pair(x, y);
        };

        used[a][b] = used[x][y] = true;
        use(a, b);
        use(x, y);
        ans.emplace_back(a, b, x, y);
        while (cand[0].size() > 1 || cand[1].size() > 1) {
            int v = cand[1].size() > 1;
            int sz = cand[v].size();
            auto [a, b] = cand[v][sz - 2];
            auto [x, y] = cand[v][sz - 1];
            cand[v].resize(sz - 2);
            use(a, b);
            use(x, y);
            ans.emplace_back(a, b, x, y);
        }
        return ans;
    };

    auto ans = solve();
    if (ans.size() * 2 == n * m) {
        cout << 1 << '\n';
        for (auto [a, b, x, y]: ans) cout << a + 1 << ' ' << b + 1 << ' ' << x + 1 << ' ' << y + 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
}