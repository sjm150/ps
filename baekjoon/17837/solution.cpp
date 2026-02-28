#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    const pi dlt[] = {make_pair(0, 1), {0, -1}, {-1, 0}, {1, 0}};
    int n, k;
    cin >> n >> k;
    vector<vector<int>> grid(n, vector<int>(n));
    for (auto &g: grid) {
        for (int &g: g) cin >> g;
    }
    vector<vector<vector<int>>> p(n, vector<vector<int>>(n));
    vector<pi> xy(k);
    vector<int> d(k);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y >> d[i];
        x--, y--, d[i]--;
        xy[i] = {x, y};
        p[x][y].push_back(i);
    }

    const int mx = 1e3;
    int ans = 1;
    for (; ans <= mx; ans++) {
        bool done = false;
        for (int i = 0; i < k; i++) {
            auto [x, y] = xy[i];
            int nx = x + dlt[d[i]].first, ny = y + dlt[d[i]].second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 2) {
                if (d[i] < 2) d[i] = 1 - d[i];
                else d[i] = 5 - d[i];
                nx = x + dlt[d[i]].first, ny = y + dlt[d[i]].second;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 2) continue;
            }

            int f = find(p[x][y].begin(), p[x][y].end(), i) - p[x][y].begin(), sz = p[x][y].size();
            for (int j = f; j < sz; j++) {
                xy[p[x][y][j]] = {nx, ny};
                p[nx][ny].push_back(p[x][y][j]);
            }
            p[x][y].resize(f);
            if (grid[nx][ny] == 1) reverse(p[nx][ny].end() - sz + f, p[nx][ny].end());
            if (int(p[nx][ny].size()) >= 4) {
                done = true;
                break;
            }
        }
        if (done) break;
    }
    cout << (ans <= mx ? ans : -1) << '\n';
}