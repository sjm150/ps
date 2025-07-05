#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> a(r, vector<int>(c));
        for (auto &a: a) {
            for (int &a: a) cin >> a;
        }

        int st = 1, en = 1;
        for (int i = 0; i < r; i++) en = max(en, *max_element(a[i].begin(), a[i].end()) + 1);

        while (st < en) {
            int m = (st + en) / 2;

            vector<vector<int>> dst(r, vector<int>(c, -1));
            queue<pair<int, int>> q;
            if (a[0][0] >= m) {
                dst[0][0] = 0;
                q.emplace(0, 0);
            }

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy]: {make_pair(-1, 0), {1, 0}, {0, -1}, {0, 1}}) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c || dst[nx][ny] >= 0) continue;
                    if (a[nx][ny] - dst[x][y] - 1 >= m) {
                        dst[nx][ny] = dst[x][y] + 1;
                        q.emplace(nx, ny);
                    }
                }
            }

            if (dst[r - 1][c - 1] >= 0) st = m + 1;
            else en = m;
        }

        if (en > 1) cout << en - 1 << '\n';
        else cout << "impossible\n";
    }
}