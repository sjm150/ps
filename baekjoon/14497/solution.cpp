#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int inf = 1e9, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    typedef tuple<int, int, int> ti;
    int n, m; cin >> n >> m;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    vector<string> grid(n);
    for (auto &s: grid) cin >> s;
    vector<vector<int>> dst(n, vector<int>(m, inf));
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    dst[x1][y1] = 0;
    pq.emplace(0, x1, y1);
    while (!pq.empty()) {
        auto [d, x, y] = pq.top(); pq.pop();
        if (d < dst[x][y]) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int nd = d + (grid[nx][ny] != '0');
            if (dst[nx][ny] > nd) {
                dst[nx][ny] = nd;
                pq.emplace(nd, nx, ny);
            }
        }
    }
    cout << dst[x2][y2] << '\n';
}