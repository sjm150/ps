#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n = 12;
    vector<vector<int>> c(n, vector<int>(n));
    for (auto &c: c) {
        for (int &c: c) cin >> c;
    }
    int ans = 1e9;
    for (int i = 0; i < (1 << (n / 2)); i++) {
        int sum = c[n - 2][n - 1];
        for (int j = 0; j < n / 2 - 1; j++) {
            int cur = (i >> j) & 1, nxt = (i >> (j + 1)) & 1;
            sum += c[j * 2][j * 2 + 1] + c[j * 2 + 1 - cur][(j + 1) * 2 + nxt];
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';
}