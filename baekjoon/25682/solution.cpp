#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<int>> cnt(n + 1, vector<int>(m + 1, 0));
    int ans = n * m;
    for (int l = 0; l < 2; l++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + ("BW"[(i + j + l) % 2] == grid[i - 1][j - 1]);
                if (i >= k && j >= k) ans = min(ans, cnt[i][j] - cnt[i - k][j] - cnt[i][j - k] + cnt[i - k][j - k]);
            }
        }
    }

    cout << ans << '\n';
}