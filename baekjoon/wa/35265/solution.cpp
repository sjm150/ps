#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int w, h;
        cin >> w >> h;
        vector<vector<bool>> ok(w, vector<bool>(h, false));
        ok[0][0] = ok[w - 1][h - 1] = true;
        for (int i = 1; i < w - 1; i++) ok[i][0] = !ok[i - 1][0];
        for (int j = h - 2; j > 0; j--) ok[w - 1][j] = !ok[w - 1][j + 1];
        if (w - 2 >= 0 && ok[w - 2][0] && h > 1 && ok[w - 1][1]) ok[w - 1][0] = false;
        else ok[w - 1][0] = true;
        vector<pair<int, int>> ans;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (!ok[i][j]) ans.emplace_back(i, j);
            }
        }
        cout << ans.size() << '\n';
        for (auto [x, y]: ans) cout << x + 1 << ' ' << y + 1 << '\n';
    }
}