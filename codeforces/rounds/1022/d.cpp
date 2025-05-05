#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        auto q = [](int i) {
            cout << "? " << i + 1 << endl;
            int c; cin >> c;
            return c;
        };
        if (n == 2 * k) {
            cout << "! " << k << ' ' << k << endl;
            continue;
        }
        if (k == 1) {
            cout << "! " << -1 << endl;
            continue;
        }

        vector<int> c(n, -1);
        for (int i = 0; i < k; i++) c[i] = q(i);
        for (int i = 0; i < k; i++) c[n - 1 - i] = q(n - 1 - i);
        vector<bool> diff(k, false);
        for (int i = 0; i < k; i++) {
            if (c[n - 1 - i] != c[(n - 1 - i) % k]) diff[(n - 1 - i) % k] = true;
        }

        vector<int> idx;
        for (int i = k; i < n - k; i++) {
            if (diff[i % k]) idx.push_back(i);
        }
        int sz = idx.size();
        if (sz == 0) {
            cout << "! " << -1 << endl;
            continue;
        }

        int l = 0, r = sz;
        while (l < r) {
            int m = (l + r) / 2;
            int mi = idx[m];
            c[mi] = q(mi);
            if (c[mi] == c[mi % k]) l = m + 1;
            else r = m;
        }

        int ans = r < sz ? idx[r] : idx[r - 1] + 1;
        if (c[ans - 1] < 0 || c[ans] < 0) {
            cout << "! " << -1 << endl;
            continue;
        }

        cout << "! " << ans << ' ' << n - ans << endl;
    }
}