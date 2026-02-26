#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<vector<int>> grid(5, vector<int>(5));
    for (auto &g: grid) {
        for (int &g: g) cin >> g;
    }
    int r, c;
    cin >> r >> c;
    bool ok = false;
    for (int i = 0; i < 64; i++) {
        auto a = grid;
        int v = i, x = r, y = c, cnt = 0;
        for (int j = 0; j < 3; j++) {
            int d = v % 4;
            v /= 4;
            a[x][y] = -1;
            x += vector({-1, 1, 0, 0})[d], y += vector({0, 0, -1, 1})[d];
            if (x < 0 || x > 4 || y < 0 || y > 4 || a[x][y] < 0) break;
            if (a[x][y]) cnt++;
        }
        if (cnt >= 2) {
            ok = true;
            break;
        }
    }
    cout << ok << '\n';
}