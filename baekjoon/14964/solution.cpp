#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int chk[][7] = {
        {1, 0, 0, 1, 1, 1, 0},
        {0, 1, 0, 2, 0, 3, 1},
        {1, 0, 2, 0, 3, 0, 1},
        {0, 1, -1, 1, -1, 2, 2},
        {1, 0, 1, 1, 2, 1, 2},
        {0, 1, 1, 1, 1, 2, 3},
        {1, 0, 1, -1, 2, -1, 3},
        {0, 1, -1, 1, 0, 2, 4},
        {1, 0, 1, 1, 2, 0, 4},
        {0, 1, 1, 1, 0, 2, 4},
        {1, 0, 1, -1, 2, 0, 4}
    };
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &s: grid) cin >> s;
    int ans[5] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') continue;
            for (auto &chk: chk) {
                bool ok = true;
                for (int k = 0; k < 3; k++) {
                    int x = i + chk[k * 2], y = j + chk[k * 2 + 1];
                    if (x < 0 || x >= n || y < 0 || y >= m || grid[i][j] != grid[x][y]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans[chk[6]]++;
                    break;
                }
            }
        }
    }
    for (int a: ans) cout << a << '\n';
}