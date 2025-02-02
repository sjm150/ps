#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<string> grid(n);
    for (auto &s: grid) cin >> s;
    int cnt, ans = 0;
    auto run = [&](int i, int j) {
        if (grid[i][j] == '.') {
            cnt++;
        } else {
            if (cnt > 1) ans++;
            cnt = 0;
        }
    };
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (int j = 0; j < n; j++) run(i, j);
        if (cnt > 1) ans++;
    }
    cout << ans << ' ';
    ans = 0;
    for (int j = 0; j < n; j++) {
        cnt = 0;
        for (int i = 0; i < n; i++) run(i, j);
        if (cnt > 1) ans++;
    }
    cout << ans << '\n';
}