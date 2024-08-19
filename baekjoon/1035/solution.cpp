#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int b = 1, s = 0, n = 0;
    for (int i = 0; i < 25; i++) {
        char c; cin >> c;
        if (c == '*') {
            s |= b;
            n++;
        }
        b *= 2;
    }
    map<int, int> dst;
    queue<int> q;
    dst[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        vector<vector<bool>> ext, vst;
        ext = vst = vector<vector<bool>>(5, vector<bool>(5, false));
        for (int i = 0, b = cur; i < 5; i++) {
            for (int j = 0; j < 5; j++, b /= 2) {
                if (b % 2) ext[i][j] = true;
            }
        }
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        function<int(int, int)> dfs = [&](int x, int y) {
            vst[x][y] = true;
            int ret = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vst[nx][ny] || !ext[nx][ny]) continue;
                ret += dfs(nx, ny);
            }
            return ret;
        };
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (ext[i][j] && !vst[i][j] && dfs(i, j) == n) {
                    cout << dst[cur] << '\n';
                    return 0;
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (!ext[i][j]) continue;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || ext[nx][ny]) continue;
                    int nxt = cur - (1 << (i * 5 + j)) + (1 << (nx * 5 + ny));
                    if (dst.find(nxt) == dst.end()) {
                        dst[nxt] = dst[cur] + 1;
                        q.push(nxt);
                    }
                }
            }
        }
    }
}