#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k, r, c; cin >> n >> m >> k >> r >> c;
    map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int g; cin >> g;
            if (g) cnt[abs(i - r) + abs(j - c) + g]++;
        }
    }
    cout << cnt.size() << '\n';
    for (auto [t, c]: cnt) cout << t << ' ' << c << '\n';
}