#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
        int o = 1, b = 1, ot = 0, bt = 0, ans = 0;
        while (n--) {
            char r;
            int p;
            cin >> r >> p;
            if (r == 'O') {
                ans = ot = max(ans + 1, abs(p - o) + 1 + ot);
                o = p;
            } else {
                ans = bt = max(ans + 1, abs(p - b) + 1 + bt);
                b = p;
            }
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}