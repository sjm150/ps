#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int r, c; cin >> r >> c;
    vector<string> ss(r);
    for (auto &s: ss) cin >> s;
    int k; cin >> k;

    bool d = k % 90;
    k = (k / 90) % 4;
    int n = k % 2 ? c : r;
    int m = k % 2 ? r : c;
    auto get = [&](int x, int y) {
        if (k == 0) return ss[x][y];
        else if (k == 1) return ss[r - 1 - y][x];
        else if (k == 2) return ss[r - 1 - x][c - 1 - y];
        else return ss[y][c - 1 - x];
    };

    if (d) {
        for (int i = 0; i < n + m - 1; i++) {
            for (int j = 0; j < abs(n - 1 - i); j++) cout << ' ';
            int s = min(n - 1, i);
            cout << get(s, i - s);
            for (int j = s - 1; j >= 0 && i - j < m; j--) cout << ' ' << get(j, i - j);
            cout << '\n';
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << get(i, j);
            cout << '\n';
        }
    }
}