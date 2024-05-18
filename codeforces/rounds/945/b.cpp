#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), f(n), b(n);
        for (int &a: a) cin >> a;

        int k = 1;
        for (int b = 1; b < (1 << 20); b <<= 1) {
            int pre = -1, mxd = 1;
            for (int i = 0; i < n; i++) {
                if ((a[i] & b) == 0) continue;
                mxd = max(mxd, i - pre);
                pre = i;
            }
            if (pre >= 0) mxd = max(mxd, n - pre);
            k = max(k, mxd);
        }

        cout << k << '\n';
    }
}