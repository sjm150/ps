#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const int ccw[] = {1, 2, 3, 0};

bool grid[101][101];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;

    while (n--) {
        int x, y, d, g;
        cin >> y >> x >> d >> g;
        vector<int> curve;
        curve.push_back(d);
        grid[x][y] = true;
        x += dx[d], y += dy[d];
        grid[x][y] = true;
        while (g--) {
            for (int i = curve.size() - 1; i >= 0; i--) {
                int d = ccw[curve[i]];
                curve.push_back(d);
                x += dx[d], y += dy[d];
                grid[x][y] = true;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1]) cnt++;
        }
    }
    cout << cnt << '\n';
}