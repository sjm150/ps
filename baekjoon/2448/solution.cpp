#include <iostream>
#include <algorithm>

using namespace std;

char grid[3072][6144];

void print(int x, int y, int n) {
    if (n == 3) {
        grid[x][y + 2] = '*';
        grid[x + 1][y + 1] = grid[x + 1][y + 3] = '*';
        grid[x + 2][y] = grid[x + 2][y + 1] = grid[x + 2][y + 2] = grid[x + 2][y + 3] = grid[x + 2][y + 4] = '*';
    } else {
        print(x, y + n / 2, n / 2);
        print(x + n / 2, y, n / 2);
        print(x + n / 2, y + n, n / 2);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) fill(grid[i], grid[i] + (n * 2), ' ');
    print(0, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2; j++) cout << grid[i][j];
        cout << '\n';
    }
}