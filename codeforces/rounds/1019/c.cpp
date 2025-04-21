#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int cur = 0, lc = 0, lf = n, rc = 0, rf = -1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] <= k) {
                cur--;
                if (cur <= 0) {
                    if (lc == 0) lf = i;
                    lc++;
                }
            } else {
                cur++;
            }
        }
        cur = 0;
        for (int i = n - 1; i > 0; i--) {
            if (a[i] <= k) {
                cur--;
                if (cur <= 0) {
                    if (rc == 0) rf = i;
                    rc++;
                }
            } else {
                cur++;
            }
        }
        cout << (lc > 1 || rc > 1 || lf + 1 < rf ? "YES\n" : "NO\n");
    }
}