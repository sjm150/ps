#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
const int hori = 0, vert = 1, diag = 2;

int n;
int grid[16][16], cnt[3][16][16];
vector<ti> prevs(int d, int x, int y) {
    if (d == hori) return {{hori, x, y - 1}, {diag, x, y - 1}};
    else if (d == vert) return {{vert, x - 1, y}, {diag, x - 1, y}};
    else return {{hori, x - 1, y - 1}, {vert, x - 1, y - 1}, {diag, x - 1, y - 1}};
}

bool oob(int x, int y) {
    if (x < 0 || n <= x || y < 0 || n <= y) return true;
    return grid[x][y] == 1;
}

bool valid(int d, int x, int y) {
    if (d == hori) return !(oob(x, y - 1) || oob(x, y));
    else if (d == vert) return !(oob(x - 1, y) || oob(x, y));
    else return !(oob(x - 1, y - 1) || oob(x - 1, y) || oob(x, y - 1) || oob(x, y));
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int j = 1; j < n; j++) {
        if (grid[0][j] == 1) break;
        cnt[hori][0][j] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 2; j < n; j++) {
            for (int d = 0; d <= 2; d++) {
                if (!valid(d, i, j)) continue;
                for (auto [pd, px, py]: prevs(d, i, j)) cnt[d][i][j] += cnt[pd][px][py];
            }
        }
    }
    cout << cnt[hori][n - 1][n - 1] + cnt[vert][n - 1][n - 1] + cnt[diag][n - 1][n - 1] << '\n';
}