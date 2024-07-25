#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll m; cin >> m;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());

        int l = 0, r = 0;
        ll ans = 0, sum = a[0];
        while (r < n) {
            if (a[r] - a[l] <= 1 && sum <= m) {
                ans = max(ans, sum);
                r++;
                if (r == n) break;
                sum += a[r];
            } else {
                sum -= a[l];
                l++;
            }
        }

        cout << ans << '\n';
    }
}