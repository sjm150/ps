#include <iostream>

using namespace std;

const int dx[4] = {-1, -1, 1, 1};
const int dy[4] = {-1, 1, -1, 1};

int n, m, k;
int cons[2001][2001];

void update_dfs(int x, int y, int oval, int nval) {
    cons[x][y] = nval;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 < nx && nx <= n && 0 < ny && ny <= m && cons[nx][ny] == oval) {
            update_dfs(nx, ny, oval, nval);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cons[i][j] = -1;
            }
        }
        for (int c = 0; c < k; c++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (cons[x1][y1] < 0) cons[x1][y1] = c;
            else update_dfs(x1, y1, cons[x1][y1], c);
            if (cons[x2][y2] < 0) cons[x2][y2] = c;
            else update_dfs(x2, y2, cons[x2][y2], c);
        }
        bool poss = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cout << cons[i][j] << ' ';
            cout << '\n';
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (cons[i][j] >= 0 && cons[i][j] == cons[i + 1][j + 1]
                    && cons[i + 1][j] >= 0 && cons[i + 1][j] == cons[i][j + 1]) {
                    poss = false;
                    break;
                }
            }
            if (!poss) break;
        }
        if (poss) cout << "YES\n";
        else cout << "NO\n";
    }
}

/**
 * why is it impossible for test case below?
 * 8 5 4
 * 1 2 2 1
 * 1 5 2 4
 * 7 1 8 2
 * 7 5 8 4
 */