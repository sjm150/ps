#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> xy(k);
    for (auto &[x, y]: xy) cin >> x >> y;
    xy.emplace_back(1, 1);
    xy.emplace_back(n, m);
    sort(xy.begin(), xy.end());
    auto solve = [&]() {
        string ans;
        for (int i = 1; i < int(xy.size()); i++) {
            auto [px, py] = xy[i - 1];
            auto [x, y] = xy[i];
            if (y < py) return string("Impossible");
            for (int j = px; j < x; j++) ans += 'D';
            for (int j = py; j < y; j++) ans += 'R';
        }
        return ans;
    };
    cout << solve() << '\n';
}