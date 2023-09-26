#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int n;
vector<vector<bool>> lit, vst, blocked;
vector<vector<pi>> edges;

bool oob(int x, int y) {
    return x <= 0 || n < x || y <= 0 || n < y;
}

int index(int x, int y) {
    return n * (x - 1) + y - 1;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m; cin >> n >> m;
    lit = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
    vst = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
    blocked = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
    edges = vector<vector<pi>>(n * n);
    while (m--) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        edges[index(x, y)].emplace_back(a, b);
    }
    queue<pi> q;
    int cnt = 1;
    lit[1][1] = true;
    vst[1][1] = true;
    q.emplace(1, 1);
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [nx, ny]: edges[index(x, y)]) {
            if (lit[nx][ny]) continue;
            lit[nx][ny] = true;
            cnt++;
            if (blocked[nx][ny] && !vst[nx][ny]) {
                vst[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (oob(nx, ny) || vst[nx][ny]) continue;
            if (!lit[nx][ny]) {
                blocked[nx][ny] = true;
                continue;
            }
            vst[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
    cout << cnt << '\n';
}