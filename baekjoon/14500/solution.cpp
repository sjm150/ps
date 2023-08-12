#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[500][500];

bool oob(int x, int y) {
    return x < 0 || n <= x || y < 0 || m <= y;
}

int sel(int x, int y, int p, int r) {
    int ret = 0;
    for (int l = 1; l <= r; l++) {
        for (int j = y - l + 1; j <= y + p - 1; j++) {
            int sum = 0;
            for (int jj = j; jj < j + l; jj++) {
                if (!oob(x, jj)) sum += grid[x][jj];
            }
            sum += sel(x + 1, j, l, r - l);
            ret = max(ret, sum);
        }
    }
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, sel(i, j, 1, 4));
    cout << ans << '\n';
}