#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int mx = n;
        for (; mx > 1; mx--) {
            cout << "? 1 " << n * mx << endl;
            int p; cin >> p;
            if (p <= n) break;
        }

        int m = mx;
        int lim = (n * mx) / k;
        bool prnt = false;
        for (; m <= lim; m += mx) {
            int idx = 1, cnt = 0;
            for (; cnt < k; cnt++) {
                cout << "? " << idx << ' ' << m << endl;
                cin >> idx;
                if (idx >= n) break;
                idx++;
            }
            if (cnt == k - 1 && idx == n) {
                cout << "! " << m << endl;
                prnt = true;
                break;
            }
        }

        if (!prnt) cout << "! " << -1 << endl;
        int res; cin >> res;
        if (res != 1) break;
    }
}