#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int r, c; cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for (auto &g: grid) {
        for (int &g: g) cin >> g;
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int d = 0; d < 4; d++) {
                bool ok = true;
                for (int ii = i + dx[d], jj = j + dy[d]; 0 <= ii && ii < r && 0 <= jj && jj < c; ii += dx[d], jj += dy[d]) {
                    if (grid[ii][jj] >= grid[i][j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) ans++;
            }
        }
    }
    cout << ans << '\n';
}