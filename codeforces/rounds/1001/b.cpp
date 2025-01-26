#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] <= 2 * max(i, n - 1 - i)) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n": "NO\n");
    }
}