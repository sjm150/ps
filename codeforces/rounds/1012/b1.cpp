#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for (auto &a: a) cin >> a;
        for (auto &b: b) cin >> b;
        for (int i = 0; i < n; i++) {
            int t = min(a[i], b[i]);
            a[i] -= t;
            b[i] -= t;
        }
        int z = 0;
        for (int a: a) {
            if (a) break;
            else z++;
        }
        int lst = 0, ans = 0;
        ll sum = 0;
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            if (sum > 0) {
                sum += a[idx] - b[idx];
                if (sum <= 0) ans = max(ans, i - lst);
            } else if (a[idx]) {
                lst = i;
                sum = a[idx];
            }
        }
        cout << ans + 1 << '\n';
    }
}