#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        int r, c, k; cin >> r >> c >> k;
        if (r == 0) break;
        vector<string> grid(r);
        for (auto &s: grid) cin >> s;
        vector<vector<int>> cnt(r + 1, vector<int>(c + 1, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cnt[i + 1][j + 1] = cnt[i + 1][j] + cnt[i][j + 1] - cnt[i][j] + (grid[i][j] == '.');
            }
        }

        int ans = r * c;
        for (int h = 1; h <= r; h++) {
            int s = 1, e = c + 1;
            while (s < e) {
                int w = (s + e) / 2;
                bool ok = false;
                for (int i = h; i <= r; i++) {
                    for (int j = w; j <= c; j++) {
                        if (cnt[i][j] - cnt[i - h][j] - cnt[i][j - w] + cnt[i - h][j - w] >= k) {
                            ok = true;
                            break;
                        }
                    }
                    if (ok) break;
                }
                if (ok) e = w;
                else s = w + 1;
            }
            if (e <= c) ans = min(ans, h * e);
        }

        cout << ans << '\n';
    }
}