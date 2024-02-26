#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> amt(n, vector<int>(n)), dst(n, vector<int>(n, 1));
    vector<tuple<int, int, int>> ord;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> amt[i][j];
            ord.emplace_back(amt[i][j], i, j);
        }
    }
    sort(ord.begin(), ord.end());

    for (auto &[a, x, y]: ord) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (amt[nx][ny] <= a) continue;
            dst[nx][ny] = max(dst[nx][ny], dst[x][y] + 1);
        }
    }

    int maxd = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dst[i][j] > maxd) maxd = dst[i][j];
        }
    }
    cout << maxd << '\n';
}