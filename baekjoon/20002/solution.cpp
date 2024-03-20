#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> ern(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ern[i][j];
            ern[i][j] += ern[i - 1][j] + ern[i][j - 1] - ern[i - 1][j - 1];
        }
    }

    int ans = -1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 1; max(i + l, j + l) <= n; l++) {
                ans = max(ans, ern[i + l][j + l] - ern[i][j + l] - ern[i + l][j] + ern[i][j]);
            }
        }
    }
    cout << ans << '\n';
}