#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int inf = 1e9;
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int ans = inf;
        for (int i = 0; i < n; i++) {
            {
                int mn = inf, mx = 0;
                for (int j = i - 1; j >= 0; j--) {
                    mn = min(mn, a[j]);
                    mx = max(mx, a[j]);
                    if (mn <= a[i] + 1 && a[i] - 1 <= mx) ans = min(ans, i - j - 1);
                }
            }
            {
                int mn = inf, mx = 0;
                for (int j = i + 1; j < n; j++) {
                    mn = min(mn, a[j]);
                    mx = max(mx, a[j]);
                    if (mn <= a[i] + 1 && a[i] - 1 <= mx) ans = min(ans, j - i - 1);
                }
            }
        }
        cout << (ans < inf ? ans : -1) << '\n';
    }
}