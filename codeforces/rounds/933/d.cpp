#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, x; cin >> n >> m >> x;
        vector<vector<bool>> ball(2, vector<bool>(n, false));
        int cur = 0, nxt = 1;
        ball[cur][x - 1] = true;

        while (m--) {
            int r; cin >> r;
            char c; cin >> c;
            fill(ball[nxt].begin(), ball[nxt].end(), false);
            for (int i = 0; i < n; i++) {
                if (ball[cur][i]) {
                    if (c != '1') ball[nxt][(i + r) % n] = true;
                    if (c != '0') ball[nxt][(i - r + n) % n] = true;
                }
            }
            swap(cur, nxt);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ball[cur][i]) cnt++;
        }
        cout << cnt << '\n';
        for (int i = 0; i < n; i++) {
            if (ball[cur][i]) cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}