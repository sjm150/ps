#include <bits/stdc++.h>
using namespace std;
const int inf = 123456789;
typedef tuple<int, int, int> ti;

const int dh[] = {-1, 1, 0, 0, 0, 0};
const int dx[] = {0, 0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, 0, -1, 1};

int cube[5][5][5];
vector<int> p = {0, 1, 2, 3, 4};
int dir[5];
int dst[5][5][5];
int mind = inf;

bool oob(int h, int x, int y) {
    return h < 0 || 5 <= h || x < 0 || 5 <= x || y < 0 || 5 <= y;
}

int get(int h, int x, int y) {
    if (dir[p[h]] == 0) return cube[p[h]][x][y];
    else if (dir[p[h]] == 1) return cube[p[h]][y][4 - x];
    else if (dir[p[h]] == 2) return cube[p[h]][4 - x][4 - y];
    else return cube[p[h]][4 - y][x];
}

void calc_dst() {
    if (get(0, 0, 0) == 0 || get(4, 4, 4) == 0) return;
    for (int h = 0; h < 5; h++) {
        for (int i = 0; i < 5; i++) {
            fill(dst[h][i], dst[h][i] + 5, -1);
        }
    }
    dst[0][0][0] = 0;
    queue<ti> q;
    q.emplace(0, 0, 0);
    while (!q.empty()) {
        auto [h, x, y] = q.front(); q.pop();
        for (int i = 0; i < 6; i++) {
            int nh = h + dh[i];
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (oob(nh, nx, ny) || get(nh, nx, ny) == 0 || dst[nh][nx][ny] >= 0) continue;
            if (nh == 4 && nx == 4 && ny == 4) {
                if (mind > dst[h][x][y] + 1) mind = dst[h][x][y] + 1;
                return;
            }
            dst[nh][nx][ny] = dst[h][x][y] + 1;
            q.emplace(nh, nx, ny);
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int h = 0; h < 5; h++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> cube[h][i][j];
            }
        }
    }
    do {
        for (int i = 0; i < 1024; i++) {
            int x = i;
            for (int h = 0; h < 5; h++) {
                dir[h] = x % 4;
                x /= 4;
            }
            calc_dst();
        }
    } while (next_permutation(p.begin(), p.end()));
    if (mind < inf) cout << mind << '\n';
    else cout << -1 << '\n';
}