#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> grid(n);
        for (auto &s: grid) cin >> s;

        vector<vector<int>> sum(n, vector<int>(m));
        auto get = [&](int i, int j) {
            if (i < 0 || j < 0) return 0;
            return sum[min(i, n - 1)][min(j, m - 1)];
        };
        int tot = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum[i][j] = get(i - 1, j) + get(i, j - 1) - get(i - 1, j - 1) + (grid[i][j] == 'g');
                tot += grid[i][j] == 'g';
            }
        }

        int mn = tot;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') mn = min(mn, get(i + k - 1, j + k - 1) - get(i - k, j + k - 1) - get(i + k - 1, j - k) + get(i - k, j - k));
            }
        }
        cout << tot - mn << '\n';
    }
}