#include <iostream>

using namespace std;

int n;
int board[10][10];
bool occup[2][19];
int max_num[2];

int get_idx0(int x, int y) {
    return x + n - 1 - y;
}

int get_idx1(int x, int y) {
    return x + y;
}

void select(int x, int y, int num) {
    if (x == n) {
        max_num[(x + y) % 2] = max(max_num[(x + y) % 2], num);
        return;
    }
    int nx = x, ny = y + 2;
    if (ny >= n) {
        nx = x + 1;
        if ((x + y) % 2 == 0) ny = 1 - x % 2;
        else ny = x % 2;
    }
    int idx0 = get_idx0(x, y);
    int idx1 = get_idx1(x, y);
    if (board[x][y] == 1 && !occup[0][idx0] && !occup[1][idx1]) {
        occup[0][idx0] = true;
        occup[1][idx1] = true;
        select(nx, ny, num + 1);
        occup[0][idx0] = false;
        occup[1][idx1] = false;
    }
    select(nx, ny, num);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    select(0, 0, 0);
    select(0, 1, 0);
    cout << max_num[0] + max_num[1] << '\n';
}