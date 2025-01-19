#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int h = 1e3 + 1, w = 1e3 + 1;
    int n; cin >> n;
    vector<vector<bool>> rb(h, vector<bool>(w, false)), bb, vst;
    bb = vst = rb;
    int px, py; cin >> px >> py;
    while (n--) {
        int x, y; cin >> x >> y;
        if (x == px) {
            for (int i = min(py, y); i < max(py, y); i++) rb[x][i] = true;
        } else {
            for (int i = min(px, x); i < max(px, x); i++) bb[i][y] = true;
        }
        px = x, py = y;
    }
    function<int(int, int)> dfs = [&](int x, int y) {
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        vst[x][y] = true;
        int cnt = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || vst[nx][ny]) continue;
            if (x == nx) {
                if (bb[x][max(y, ny)]) continue;
            } else {
                if (rb[max(x, nx)][y]) continue;
            }
            cnt += dfs(nx, ny);
        }
        return cnt;
    };
    dfs(0, 0);
    int ans = 0;
    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (!vst[i][j]) ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << '\n';
}