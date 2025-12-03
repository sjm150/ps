#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &g: grid) cin >> g;

    vector<pair<int, int>> lr(n);
    int mxh = 0;
    for (int i = 0; i < n; i++) {
        int l = -1, r = -1;
        for (int j = 0; j < m; j++) {
            if (grid[n - i - 1][j] == 'J') {
                if (l < 0) l = j;
                r = j;
            }
        }
        lr[i] = {l, r};
        if (l >= 0) mxh = i;
    }

    int cur = lr[0].second, ans = mxh + cur;
    for (int i = 1; i < n; i++) {
        auto [l, r] = lr[i];
        if (l < 0) continue;
        ans += r - l + abs((i % 2 ? r : l) - cur);
        cur = i % 2 ? l : r;
    }
    cout << ans << '\n';
}