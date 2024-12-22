#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int sz = 2 * n;
        if (sz <= m) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<vector<int>> c(sz, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) c[(i + 2 * j) % sz][i] = c[(i + 2 * j + 1) % sz][i] = j + 1;
        }
        for (auto &c: c) {
            for (int c: c) cout << c << ' ';
            cout << '\n';
        }
    }
}