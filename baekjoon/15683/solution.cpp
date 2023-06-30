#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
int room[8][8];
int monitored[8][8];
vector<pair<int, int>> cctvs;
int min_count;

int count() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (monitored[i][j] == 0) ret++;
        }
    }
    return ret;
}

void add(int x, int y, int val, int dir) {
    x += dx[dir];
    y += dy[dir];
    while (room[x][y] != 6 && 0 <= x && x < n && 0 <= y && y < m) {
        monitored[x][y] += val;
        x += dx[dir];
        y += dy[dir];
    }
}

void select(int idx) {
    if (idx == cctvs.size()) {
        min_count = min(min_count, count());
        return;
    }
    int x, y;
    tie(x, y) = cctvs[idx];
    int kind = room[x][y];
    if (kind == 1) {
        for (int i = 0; i < 4; i++) {
            add(x, y, 1, i);
            select(idx + 1);
            add(x, y, -1, i);
        }
    } else if (kind == 2) {
        for (int i = 0; i < 2; i++) {
            add(x, y, 1, i);
            add(x, y, 1, i + 2);
            select(idx + 1);
            add(x, y, -1, i);
            add(x, y, -1, i + 2);
        }
    } else if (kind == 3) {
        for (int i = 0; i < 4; i++) {
            add(x, y, 1, i);
            add(x, y, 1, (i + 1) % 4);
            select(idx + 1);
            add(x, y, -1, i);
            add(x, y, -1, (i + 1) % 4);
        }
    } else if (kind == 4) {
        for (int i = 0; i < 4; i++) {
            add(x, y, 1, i);
            add(x, y, 1, (i + 1) % 4);
            add(x, y, 1, (i + 2) % 4);
            select(idx + 1);
            add(x, y, -1, i);
            add(x, y, -1, (i + 1) % 4);
            add(x, y, -1, (i + 2) % 4);
        }
    } else if (kind == 5) {
        add(x, y, 1, 0);
        add(x, y, 1, 1);
        add(x, y, 1, 2);
        add(x, y, 1, 3);
        select(idx + 1);
        add(x, y, -1, 0);
        add(x, y, -1, 1);
        add(x, y, -1, 2);
        add(x, y, -1, 3);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
            if (room[i][j] != 0) {
                if (room[i][j] != 6) cctvs.emplace_back(i, j);
                monitored[i][j] = 1;
            }
        }
    }
    min_count = n * m;
    select(0);
    cout << min_count << '\n';
}