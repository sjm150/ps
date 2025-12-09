#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int w, h;
        cin >> w >> h;
        vector<string> grid(h);
        for (auto &g: grid) cin >> g;

        int sz = w + h - 1;
        vector<vector<vector<int>>> cnt(sz, vector<vector<int>>(h, vector<int>(h, 0)));
        auto get = [&](int d, int i) { return grid[i][d - i]; };
        auto chk = [&](int d, int i) { return 0 <= d - i && d - i < w && i < h && get(d, i) != '#'; };

        for (int d = 0; d < sz - 1; d++) {
            for (int i = max(d - w + 1, 0); i <= min(d, h - 1); i++) {
                if (!chk(d, i)) continue;
                for (int j = max(d - w + 1, 0); j <= min(d, h - 1); j++) {
                    if (!chk(d, j)) continue;
                    for (int ni = max(d - w + 2, i); ni <= min(i + 1, h - 1); ni++) {
                        if (!chk(d + 1, ni)) continue;
                        for (int nj = max(d - w + 2, j); nj <= min(j + 1, h - 1); nj++) {
                            if (!chk(d + 1, nj)) continue;
                            if (ni == nj) cnt[d + 1][ni][nj] = max(cnt[d + 1][ni][nj], cnt[d][i][j] + (get(d + 1, ni) == '*'));
                            else cnt[d + 1][ni][nj] = max(cnt[d + 1][ni][nj], cnt[d][i][j] + (get(d + 1, ni) == '*') + (get(d + 1, nj) == '*'));
                        }
                    }
                }
            }
        }

        cout << (grid[0][0] == '*') + cnt[sz - 1][h - 1][h - 1] << '\n';
    }
}