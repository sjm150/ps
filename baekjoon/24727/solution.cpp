#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, c, e; cin >> n >> c >> e;
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; c; i++) {
        for (int j = min(n - 1, i); c && j >= 0 && i - j < n; j--) {
            ans[i - j][j] = 1;
            ans[i - j + 1][j] = 0;
            ans[i - j][j + 1] = 0;
            c--;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (ans[i][j] >= 0) break;
            if (e) {
                ans[i][j] = 2;
                e--;
            } else {
                ans[i][j] = 0;
            }
        }
    }

    if (e) {
        cout << -1 << '\n';
    } else {
        cout << 1 << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << ans[i][j];
            cout << '\n';
        }
    }
}