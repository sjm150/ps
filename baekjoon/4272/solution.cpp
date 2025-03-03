#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int c; cin >> c;
    while (c--) {
        int l, m; cin >> l >> m;
        l *= 100;
        int lsum = 0, rsum = 0, lcnt = 0, rcnt = 0;
        while (m--) {
            int len; cin >> len;
            string p; cin >> p;
            if (p[0] == 'l') {
                if (lsum + len > l) {
                    lsum = len;
                    lcnt++;
                } else {
                    lsum += len;
                }
            } else {
                if (rsum + len > l) {
                    rsum = len;
                    rcnt++;
                } else {
                    rsum += len;
                }
            }
        }
        if (lsum) lcnt++;
        if (rsum) rcnt++;
        cout << max(lcnt * 2 - 1, rcnt * 2) << '\n';
    }
}