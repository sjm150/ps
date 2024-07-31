#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> grid(2);
        for (auto &s: grid) cin >> s;
        int ans = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == '.' && grid[1 - i][j] == '.' && grid[i][j - 1] == '.' && grid[i][j + 1] == '.' && grid[1 - i][j - 1] == 'x' && grid[1 - i][j + 1] == 'x') {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}