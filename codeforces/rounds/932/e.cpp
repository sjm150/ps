#include <bits/stdc++.h>
using namespace std;
const int mx = 30;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> bsum(n + 1), fsum(n + 1);
        bsum[0] = fsum[0] = vector<int>(mx, 0);
        for (int i = 1; i <= n; i++) {
            int x, y; cin >> x >> y;
            bsum[i] = bsum[i - 1];
            fsum[i] = fsum[i - 1];

            int j = mx - 1;
            int b = 1 << j;
            for (; j >= 0 && (x & b) == (y & b); j--, b >>= 1) {
                if (y & b) fsum[i][j]++;
            }
            for (; j >= 0; j--, b >>= 1) {
                if (y & b) bsum[i][j]++;
            }
        }

        int q; cin >> q;
        while (q--) {
            int l, r; cin >> l >> r;
            int v = 0;

            int j = mx - 1;
            int b = 1 << j;
            for (; j >= 0; j--, b >>= 1) {
                int bs = bsum[r][j] - bsum[l - 1][j];
                int fs = fsum[r][j] - fsum[l - 1][j];
                if (bs >= 1 && bs + fs >= 2) {
                    v |= b - 1 + b;
                    break;
                } else if (bs == 1 || fs >= 1) {
                    v |= b;
                }
            }

            cout << v << ' ';
        }
        cout << '\n';
    }
}