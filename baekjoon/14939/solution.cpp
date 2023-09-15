#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int n = 10;

char grid[n][n];
int pcnt;
bool on[n][n];

bool oob(int x, int y) {
    return x < 0 || n <= x || y < 0 || n <= y;
}

void push(int x, int y) {
    pcnt++;
    on[x][y] = !on[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (oob(nx, ny)) continue;
        on[nx][ny] = !on[nx][ny];
    }
}

bool contains(int x, int b) {
    return x & (1 << b);
}

void init(int fst) {
    pcnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'O') on[i][j] = true;
            else on[i][j] = false;
        }
    }
    for (int j = 0; j < n; j++) {
        if (contains(fst, j)) push(0, j);
    }
}

void run() {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (on[i - 1][j]) push(i, j);
        }
    }
}

bool isdone() {
    for (int j = 0; j < n; j++) {
        if (on[n - 1][j]) return false;
    }
    return true;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    for (int i = 0; i < 1024; i++) {
        init(i);
        run();
        if (isdone()) {
            cout << pcnt << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}