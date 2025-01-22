#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());
        int idx = -1;
        for (int i = n - 1; i; i--) {
            if (a[i - 1] == a[i]) {
                idx = i - 1;
                break;
            }
        }
        bool ok = false;
        if (idx >= 0) {
            int p = -1;
            for (int i = 0; i < n; i++) {
                if (i == idx || i == idx + 1) continue;
                if (p >= 0 && 2 * a[idx] + p > a[i]) {
                    cout << a[idx] << ' ' << a[idx + 1] << ' ' << p << ' ' << a[i] << '\n';
                    ok = true;
                    break;
                }
                p = a[i];
            }
        }
        if (!ok) cout << -1 << '\n';
    }
}