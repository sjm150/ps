#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<string> s(2);
    cin >> s[0] >> s[1];

    vector<vector<int>> dst(2, vector<int>(n, -1));
    queue<pair<int, int>> q;
    dst[0][0] = 0;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy]: {make_pair(0, -1), {0, 1}, {1 - 2 * x, k}}) {
            int nx = x + dx, ny = y + dy;
            if (ny < 0 || ny >= n || s[nx][ny] == '0' || dst[nx][ny] >= 0 || dst[x][y] + 1 > ny) continue;
            dst[nx][ny] = dst[x][y] + 1;
            q.emplace(nx, ny);
        }
    }

    bool ok = false;
    for (int i = max(0, n - k); i < n; i++) {
        if (dst[0][i] >= 0 || dst[1][i] >= 0) {
            ok = true;
            break;
        }
    }
    cout << ok << '\n';
}