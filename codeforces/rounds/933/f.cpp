#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(n), d(m), f(k);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> d[i];
        for (int i = 0; i < k; i++) cin >> f[i];
        sort(f.begin(), f.end());

        int maxd[2] = {0, 0};
        int maxi = -1;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] > maxd[0]) {
                maxd[1] = maxd[0];
                maxd[0] = a[i] - a[i - 1];
                maxi = i - 1;
            } else if (a[i] - a[i - 1] > maxd[1]) {
                maxd[1] = a[i] - a[i - 1];
            }
        }

        auto val = [&](int x) { return max(abs(x - a[maxi]), abs(x - a[maxi + 1])); };
        for (int d: d) {
            int l = 0, r = k - 1;
            while ((r - l) >= 3) {
                int dlt = (r - l) / 3;
                int lv = val(f[l + dlt] + d), rv = val(f[r - dlt] + d);
                if (lv > rv) l += dlt;
                else r -= dlt;
            }
            maxd[0] = min(min(maxd[0], val(f[l] + d)), min(val(f[l + 1] + d), val(f[l + 2] + d)));
        }

        cout << max(maxd[0], maxd[1]) << '\n';
    }
}