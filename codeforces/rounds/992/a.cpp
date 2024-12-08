#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (abs(a[i] - a[j]) % k == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = i + 1;
                break;
            }
        }
        if (ans) {
            cout << "YES\n";
            cout << ans << '\n';
        } else {
            cout << "NO\n";
        }
    }
}