#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int ans = 0;
        while (n--) {
            int dx, dy, x, y;
            cin >> dx >> dy >> x >> y;
            if (x == y && dx * dy == 1) ans++;
            else if (x + y == s && dx * dy == -1) ans++;
        }
        cout << ans << '\n';
    }
}