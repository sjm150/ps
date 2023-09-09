#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int w, h;
char grid[100][100];
int cnt[100][100];
int dir[100][100];

bool contains(int d, int x) {
    return (d & (1 << x));
}

int add(int d, int x) {
    return (d | (1 << x));
}

bool oob(int x, int y) {
    return x < 0 || h <= x || y < 0 || w <= y;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> w >> h;
    int xs, ys, xe, ye;
    xs = ys = xe = ye = -1;
    for (int i = 0; i < h; i++) {
        string line; cin >> line;
        for (int j = 0; j < w; j++) {
            grid[i][j] = line[j];
            if (grid[i][j] == 'C') {
                if (xs == -1) xs = i, ys = j;
                else xe = i, ye = j;
            }
        }
    }
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    for (int i = 0; i < h; i++) fill(cnt[i], cnt[i] + w, 100000);
    cnt[xs][ys] = 0;
    dir[xs][ys] = (1 << 4) - 1;
    pq.emplace(cnt[xs][ys], xs, ys);
    while (!pq.empty()) {
        auto [c, x, y] = pq.top(); pq.pop();
        if (c != cnt[x][y]) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (oob(nx, ny) || grid[nx][ny] == '*') continue;
            int nc = c;
            if (!contains(dir[x][y], i)) nc++;
            if (cnt[nx][ny] > nc) {
                cnt[nx][ny] = nc;
                dir[nx][ny] = add(0, i);
                pq.emplace(nc, nx, ny);
            } else if (cnt[nx][ny] == nc) {
                dir[nx][ny] = add(dir[nx][ny], i);
            }
        }
    }
    cout << cnt[xe][ye] << '\n';
}