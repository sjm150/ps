#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    const pi dlt[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int k;
    cin >> k;
    for (int tc = 1; tc <= k; tc++) {
        int n, m, x, y, t;
        cin >> m >> n >> y >> x >> t;
        x--, y--;

        vector<vector<pi>> grid(n, vector<pi>(m));
        for (auto &g: grid) {
            for (auto &[s, d]: g) {
                char c;
                cin >> s >> c;
                if (c == 'N') d = 0;
                else if (c == 'S') d = 1;
                else if (c == 'W') d = 2;
                else d = 3;
            }
        }

        vector<vector<int>> vst(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        vst[x][y] = 0;
        q.emplace(x, y);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (vst[x][y] > t) break;
            auto [s, d] = grid[x][y];
            auto [dx, dy] = dlt[d];
            for (int i = 1; i <= s; i++) {
                int nx = x + dx * i, ny = y + dy * i;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
                if (vst[nx][ny] < 0) {
                    vst[nx][ny] = vst[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }

        cout << "Data Set " << tc << ":\n";
        for (auto &v: vst) {
            for (int v: v) cout << (0 <= v && v <= t ? 'X' : '.');
            cout << '\n';
        }
        cout << '\n';
    }
}