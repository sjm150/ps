#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int r, c; cin >> r >> c;
    vector<string> grid(r);
    for (auto &s: grid) cin >> s;
    int ans = 1;
    vector<int> cnt(c, 0);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cnt[j] = grid[i][j] == '.' ? cnt[j] + 1 : 0;
        for (int j = 0; j < c; j++) {
            int mn = cnt[j];
            for (int k = j; k >= 0; k--) {
                mn = min(mn, cnt[k]);
                if (mn == 0) break;
                ans = max(ans, (mn + j - k + 1) * 2);
            }
        }
    }
    cout << ans - 1 << '\n';
}