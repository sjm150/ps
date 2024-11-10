#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n);
        if (n % 2) {
            cout << n << '\n';
            for (int i = 0; i < n - 4; i++) p[i] = i + 2;
            p[n - 4] = n - 2;
            p[n - 3] = 1;
            p[n - 2] = n - 1;
            p[n - 1] = n;
        } else {
            int mxb = 1;
            while (mxb * 2 <= n) mxb *= 2;
            cout << mxb * 2 - 1 << '\n';
            int cur = n;
            for (int i = 0; i < n - 4;) {
                if (cur == mxb || cur == mxb - 1 || cur == mxb - 2 || cur == mxb - 3) cur--;
                else p[i++] = cur--;
            }
            p[n - 4] = mxb - 3;
            p[n - 3] = mxb - 2;
            p[n - 2] = mxb - 1;
            p[n - 1] = mxb;
        }
        for (int p: p) cout << p << ' ';
        cout << '\n';
    }
}