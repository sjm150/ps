#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, m;
int map[50][50];
int dst[50][50];
vector<pair<int, int>> home;
vector<pair<int, int>> chkn;
bool p[13];

int total_dst() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dst[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < chkn.size(); i++) {
        if (p[i]) {
            q.emplace(chkn[i].first, chkn[i].second);
            dst[chkn[i].first][chkn[i].second] = 0;
        }
    }
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && dst[nx][ny] < 0) {
                q.emplace(nx, ny);
                dst[nx][ny] = dst[x][y] + 1;
            }
        }
    }
    int total = 0;
    for (auto& h: home) total += dst[h.first][h.second];
    return total;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) home.emplace_back(i, j);
            else if (map[i][j] == 2) chkn.emplace_back(i, j);
        }
    }
    fill(p + chkn.size() - m, p + chkn.size(), true);
    int min_dst = 100000;
    do {
        min_dst = min(min_dst, total_dst());
    } while (next_permutation(p, p + chkn.size()));
    cout << min_dst << '\n';
}