#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> grid(2);
        cin >> grid[0] >> grid[1];
 
        auto oob = [&](int x, int y) {
            return x < 0 || x >= 2 || y < 0 || y >= n;
        };
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
 
        vector<vector<bool>> vst(2, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vst[0][0] = true;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (oob(nx, ny)) continue;
                if (grid[nx][ny] == '>') ny++;
                else ny--;
                if (!vst[nx][ny]) {
                    vst[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
 
        cout << (vst[1][n - 1] ? "YES\n" : "NO\n");
    }
}