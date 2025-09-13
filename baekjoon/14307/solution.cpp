#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int r, c, sr, sc, s;
        double p, q;
        cin >> r >> c >> sr >> sc >> s >> p >> q;
        vector<vector<char>> grid(r, vector<char>(c));
        for (auto &g: grid) {
            for (auto &g: g) cin >> g;
        }

        double ans = 0;
        int mx = 1 << (2 * s);
        for (int v = 0; v < mx; v++) {
            vector<pair<int, int>> d;
            for (int i = 0, r = v; i < s; i++, r /= 4) {
                switch (r % 4) {
                    case 0: d.emplace_back(0, 1); break;
                    case 1: d.emplace_back(0, -1); break;
                    case 2: d.emplace_back(1, 0); break;
                    case 3: d.emplace_back(-1, 0); break;
                }
            }

            int x = sr, y = sc;
            vector<vector<double>> rem(r, vector<double>(c, 1));
            double sum = 0;
            bool oob = false;
            for (auto [dx, dy]: d) {
                x += dx, y += dy;
                if (x < 0 || x >= r || y < 0 || y >= c) {
                    oob = true;
                    break;
                }
                double w = grid[x][y] == 'A' ? p : q;
                sum += rem[x][y] * w;
                rem[x][y] *= 1 - w;
            }
            if (!oob) ans = max(ans, sum);
        }

        cout << setprecision(7) << fixed << "Case #" << tc << ": " << ans << '\n';
    }
}