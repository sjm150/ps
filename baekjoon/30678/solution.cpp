#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int sz = 1;
    for (int i = 0; i < n; i++) sz *= 5;
    vector<string> ans(sz, string(sz, ' '));
    function<void(int, int, int, int)> dfs = [&](int x1, int x2, int y1, int y2) {
        int d = x2 - x1;
        if (d == 1) {
            ans[x1][y1] = '*';
            return;
        }
        d /= 5;
        dfs(x1, x1 + d, y1 + 2 * d, y1 + 3 * d);
        dfs(x1 + d, x1 + 2 * d, y1 + 2 * d, y1 + 3 * d);
        for (int i = 0; i < 5; i++) dfs(x1 + 2 * d, x1 + 3 * d, y1 + i * d, y1 + (i + 1) * d);
        for (int i = 1; i < 4; i++) dfs(x1 + 3 * d, x1 + 4 * d, y1 + i * d, y1 + (i + 1) * d);
        for (int i = 1; i < 4; i += 2) dfs(x1 + 4 * d, x1 + 5 * d, y1 + i * d, y1 + (i + 1) * d);
    };
    dfs(0, sz, 0, sz);
    for (auto &s: ans) cout << s << '\n';
}