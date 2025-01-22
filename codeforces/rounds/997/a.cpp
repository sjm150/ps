#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int x, y; cin >> x >> y;
        int ans = n * m * 4;
        for (int i = 0; i < n - 1; i++) {
            int dx, dy; cin >> dx >> dy;
            ans -= 2 * (m - dx) + 2 * (m - dy);
            x += dx, y += dy;
        }
        cout << ans << '\n';
    }
}