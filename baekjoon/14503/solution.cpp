#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
int grid[50][50];

int rev(int d) {
    if (d % 2) return 4 - d;
    else return 2 - d;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int x, y, d; cin >> x >> y >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int cnt = 0;
    while (true) {
        if (grid[x][y] == 0) {
            grid[x][y] = -1;
            cnt++;
        }

        bool go = false;
        for (int i = 1; i <= 4; i++) {
            int nd = (d - i + 4) % 4;
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            if (grid[nx][ny]) continue;
            d = nd, x = nx, y = ny;
            go = true;
            break;
        }
        if (go) continue;

        int rd = rev(d);
        int nx = x + dx[rd];
        int ny = y + dy[rd];
        if (grid[nx][ny] == 1) break;
        x = nx, y = ny;
    }

    cout << cnt << '\n';
}