#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &g: grid) {
        for (int &g: g) cin >> g;
    }

    map<int, int> cnt;
    for (int i = 0; i < n; i++) cnt[grid[i][0]]++;
    for (int j = 0; j < m; j++) cnt[grid[0][0] - grid[0][j]]++;
    int mx = 0, z = 0;
    for (auto [v, cnt]: cnt) {
        if (mx < cnt) {
            mx = cnt;
            z = v;
        }
    }

    vector<vector<int>> res(n, vector<int>(m, 0));
    vector<tuple<int, int, int>> ans;
    for (int i = 0; i < n; i++) {
        int v = grid[i][0] - z;
        if (!v) continue;
        ans.emplace_back(1, i + 1, v);
        for (int j = 0; j < m; j++) res[i][j] += v;
    }
    for (int j = 0; j < m; j++) {
        int v = grid[0][j] - grid[0][0] + z;
        if (!v) continue;
        ans.emplace_back(2, j + 1, v);
        for (int i = 0; i < n; i++) res[i][j] += v;
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res[i][j] != grid[i][j]) {
                ok = false;
                break;
            }
        }
        if (!ok) break;
    }
    if (ok) {
        cout << ans.size() << '\n';
        for (auto [c, i, v]: ans) cout << c << ' ' << i << ' ' << v << '\n';
    } else {
        cout << -1 << '\n';
    }
}