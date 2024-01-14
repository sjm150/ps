#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k, x; cin >> n >> k >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        int maxs = -1e9, sum = 0;
        if (n == k) maxs = 0;
        for (int i = 0; i < n; i++) {
            sum -= a[i];
            if (i >= x) sum += a[i - x] * 2;
            if (i >= n - k - 1) maxs = max(sum, maxs);
        }

        cout << maxs << '\n';
    }
}