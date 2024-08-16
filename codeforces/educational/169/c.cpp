#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end(), greater<int>());
        long long ans = 0;
        for (int i = 0; i < n - 1; i += 2) {
            int d = a[i] - a[i + 1];
            if (k >= d) {
                k -= d;
            } else {
                ans += d - k;
                k = 0;
            }
        }
        if (n % 2) ans += a.back();
        cout << ans << '\n';
    }
}