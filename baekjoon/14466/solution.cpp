#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k, r; cin >> n >> k >> r;
    set<tuple<int, int, int, int>> blk;
    while (r--) {
        int r0, c0, r1, c1; cin >> r0 >> c0 >> r1 >> c1;
        r0--, c0--, r1--, c1--;
        blk.emplace(r0, c0, r1, c1);
        blk.emplace(r1, c1, r0, c0);
    }
    vector<vector<bool>> occ, vst;
    occ = vst = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        occ[r - 1][c - 1] = true;
    }

    int cnt = 0;
    auto bfs = [&](int r, int c) {
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        queue<pi> q;
        vst[r][c] = true;
        q.emplace(r, c);
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (occ[x][y]) cnt++;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || vst[nx][ny]) continue;
                if (blk.find(make_tuple(x, y, nx, ny)) != blk.end()) continue;
                vst[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    };

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vst[i][j]) continue;
            bfs(i, j);
            ans += cnt * (k - cnt);
            cnt = 0;
        }
    }
    cout << ans / 2 << '\n';
}