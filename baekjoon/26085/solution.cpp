#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &g: grid) {
        for (int &g: g) cin >> g;
    }

    auto solve = [&]() {
        int z = 0, o = 0;
        for (auto &g: grid) {
            for (int g: g) (g ? o : z)++;
        }
        if (z % 2 || o % 2) return false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j + 1 < m && grid[i][j] == grid[i][j + 1]) return true;
                if (i + 1 < n && grid[i][j] == grid[i + 1][j]) return true;
            }
        }
        return false;
    };

    cout << (solve() ? 1 : -1) << '\n';
}