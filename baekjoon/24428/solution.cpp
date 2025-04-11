#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (auto &g: grid) {
        for (int &g: g) cin >> g;
    }
    int p; cin >> p;
    vector<vector<bool>> req(n, vector<bool>(n, false));
    while (p--) {
        int r, c; cin >> r >> c;
        req[r - 1][c - 1] = true;
    }
    const int inf = 2e9;
    vector<vector<vector<int>>> scr(4, vector<vector<int>>(n, vector<int>(n, -inf)));
    scr[0][0][0] = grid[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int t = -inf;
                if (i) t = max(t, scr[k][i - 1][j]);
                if (j) t = max(t, scr[k][i][j - 1]);
                int kk = min(3, k + req[i][j]);
                scr[kk][i][j] = max(scr[kk][i][j], t + grid[i][j]);
            }
        }
    }
    cout << (scr[3][n - 1][n - 1] > 0 ? scr[3][n - 1][n - 1] : -1) << '\n';
}