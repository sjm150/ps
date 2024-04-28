#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> grid(n);
        for (auto &l: grid) cin >> l;

        bool aw, ab, w, b;
        aw = ab = false;

        auto iter = [&](int i, int j) {
            if (grid[i][j] == 'W') w = true;
            else b = true;
        };
        auto appl = [&]() {
            if (w && !b) aw = true;
            else if (!w && b) ab = true;
        };

        w = b = false;
        for (int i = 0; i < n; i++) iter(i, 0);
        appl();
        w = b = false;
        for (int i = 0; i < n; i++) iter(i, m - 1);
        appl();
        w = b = false;
        for (int j = 0; j < m; j++) iter(0, j);
        appl();
        w = b = false;
        for (int j = 0; j < m; j++) iter(n - 1, j);
        appl();

        cout << (ab && aw ? "NO\n" : "YES\n");
    }
}