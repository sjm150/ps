#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());

        int l = 0, r = 1e6 + 1;
        while (l < r) {
            int m = (l + r) / 2;
            ll lsum = 0, rsum = 0;
            for (int a: a) {
                if (a > m) rsum += a - m;
                else if (a < m - k - 1) lsum += m - k - 1 - a;
            }
            if (lsum < rsum) l = m + 1;
            else r = m;
        }

        ll rsum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] <= r) break;
            rsum += a[i] - r;
            a[i] = r;
        }

        ll lsum = a[0];
        for (int i = 1; i < n; i++) {
            ll sum = lsum + rsum;
            if (sum / i <= a[i]) {
                for (int j = 0; j < i; j++) a[j] = sum / i + (j < sum % i);
                break;
            }
            lsum += a[i];
        }

        ll ans = rsum * k;
        multiset<int> ms(a.begin(), a.end());
        while (*prev(ms.end()) - *ms.begin() - 1 - k > 0) {
            int l = *ms.begin(), r = *prev(ms.end());
            ms.erase(ms.begin());
            ms.erase(prev(ms.end()));
            ans += k;
            ms.insert(l + 1);
            ms.insert(r - 1);
        }
        for (int a: ms) ans += a * ll(a + 1) / 2;
        cout << ans << '\n';
    }
}