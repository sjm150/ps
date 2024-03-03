#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> grid(2);
        for (int i = 0; i < 2; i++) cin >> grid[i];

        vector<vector<int>> cnt(2, vector<int>(n, 0));
        string s = "";
        cnt[0][0] = 1;
        s += grid[0][0];
        for (int j = 1; j < n; j++) {
            if (grid[0][j] == grid[1][j - 1]) {
                cnt[0][j] = cnt[0][j - 1];
                if (j == 1) cnt[1][j - 1] = 1;
                else cnt[1][j - 1] = cnt[0][j - 1] + cnt[1][j - 2];
                s += grid[0][j];
            } else if (grid[0][j] == '0') {
                cnt[0][j] = cnt[0][j - 1];
                if (cnt[0][j]) {
                    s += '0';
                } else {
                    if (j == 1) cnt[1][j - 1] = 1;
                    else cnt[1][j - 1] = cnt[0][j - 1] + cnt[1][j - 2];
                    s += '1';
                }
            } else {
                if (j == 1) cnt[1][j - 1] = 1;
                else cnt[1][j - 1] = cnt[0][j - 1] + cnt[1][j - 2];
                s += '0';
            }
        }
        s += grid[1][n - 1];

        cout << s << '\n';
        cout << cnt[0][n - 1] + cnt[1][n - 2] << '\n';
    }
}