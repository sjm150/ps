#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(n), d(m), f(k);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> d[i];
        for (int i = 0; i < k; i++) cin >> f[i];
        sort(d.begin(), d.end());
        sort(f.begin(), f.end());

        int maxi = 0, lim = 0;
        for (int i = 1; i < n - 1; i++) {
            if (a[maxi + 1] - a[maxi] < a[i + 1] - a[i]) {
                lim = a[maxi + 1] - a[maxi];
                maxi = i;
            } else if (lim < a[i + 1] - a[i]) {
                lim = a[i + 1] - a[i];
            }
        }

        int l = a[maxi], r = a[maxi + 1];
        int tar = (ll(l) + r) / 2;
        int j = k - 1;
        int ans = r - l;
        for (int i = 0; i < m; i++) {
            while (j >= 0 && d[i] + f[j] > tar) j--;
            if (j >= 0) ans = min(ans, max(abs(d[i] + f[j] - l), abs(d[i] + f[j] - r)));
            if (j < k - 1) ans = min(ans, max(abs(d[i] + f[j + 1] - l), abs(d[i] + f[j + 1] - r)));
        }

        cout << max(ans, lim) << '\n';
    }
}