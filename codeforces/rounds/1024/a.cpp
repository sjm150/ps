#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> ans(n, vector<int>(n));
        int sx, sy, ex, ey;
        sx = sy = ex = ey = (n - 1) / 2;
        ans[sx][sy] = 0;
        for (int i = 0, cur = 1; i < n - 1; i++) {
            if (i % 2) {
                sx--, sy--;
                for (int i = sx + 1; i <= ex; i++) ans[i][sy] = cur++;
                for (int i = sy + 1; i <= ey; i++) ans[sx][i] = cur++;
                ans[sx][sy] = cur++;
            } else {
                ex++, ey++;
                for (int i = sx; i < ex; i++) ans[i][ey] = cur++;
                for (int i = sy; i < ey; i++) ans[ex][i] = cur++;
                ans[ex][ey] = cur++;
            }
        }
        for (auto &a: ans) {
            for (int a: a) cout << a << ' ';
            cout << '\n';
        }
    }
}