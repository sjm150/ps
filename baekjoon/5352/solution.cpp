#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> grid(n);
        for (auto &s: grid) cin >> s;

        vector<vector<int>> cnt(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cnt[i][j] = (grid[i - 1][j - 1] == 'C') + max(cnt[i - 1][j], cnt[i][j - 1]);
            }
        }
        cout << cnt[n][m] << '\n';
    }
}