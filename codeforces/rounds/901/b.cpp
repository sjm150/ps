#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 100;

int a[50], b[50];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        ll asum = 0;
        int amin = inf, amax = 0, bmin = inf, bmax = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            asum += a[i];
            amin = min(amin, a[i]);
            amax = max(amax, a[i]);
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            bmin = min(bmin, b[i]);
            bmax = max(bmax, b[i]);
        }
        if (amin <= bmin && amax <= bmax) {
            if (k % 2) cout << asum - amin + bmax << '\n';
            else cout << asum << '\n';
        } else {
            if (bmax > amin) asum += bmax - amin;
            if (k % 2) cout << asum << '\n';
            else cout << asum + min(amin, bmin) - max(amax, bmax) << '\n';
        }
    }
}