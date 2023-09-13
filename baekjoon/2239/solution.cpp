#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int grid[9][9];
vector<pi> blanks;
int row[9], col[9], cel[9];

bool contains(int x, int b) {
    return x & (1 << b);
}

int addbit(int x, int b) {
    return x | (1 << b);
}

int delbit(int x, int b) {
    return x & ~(1 << b);
}

int cel_idx(int x, int y) {
    return x / 3 * 3 + y / 3;
}

bool select(int i) {
    if (i == blanks.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << grid[i][j];
            cout << '\n';
        }
        return true;
    }
    auto [x, y] = blanks[i];
    int c = cel_idx(x, y);
    for (int n = 1; n <= 9; n++) {
        if (contains(row[x], n)) continue;
        if (contains(col[y], n)) continue;
        if (contains(cel[c], n)) continue;
        grid[x][y] = n;
        row[x] = addbit(row[x], n);
        col[y] = addbit(col[y], n);
        cel[c] = addbit(cel[c], n);
        if (select(i + 1)) return true;
        grid[x][y] = 0;
        row[x] = delbit(row[x], n);
        col[y] = delbit(col[y], n);
        cel[c] = delbit(cel[c], n);
    }
    return false;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int i = 0; i < 9; i++) {
        string line; cin >> line;
        for (int j = 0; j < 9; j++) {
            grid[i][j] = line[j] - '0';
            if (grid[i][j] == 0) {
                blanks.emplace_back(i, j);
            } else {
                row[i] = addbit(row[i], grid[i][j]);
                col[j] = addbit(col[j], grid[i][j]);
                cel[cel_idx(i, j)] = addbit(cel[cel_idx(i, j)], grid[i][j]);
            }
        }
    }
    select(0);
}