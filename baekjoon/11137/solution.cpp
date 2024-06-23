#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, l; cin >> n >> l;
        double p; cin >> p;
        double ans = 0;
        vector<double> prb(l, 0);
        prb[0] = 1;
        for (int i = 0; i < n; i++) {
            double sum = 1 - ans;
            ans += prb[l - 1] * (1 - p);
            for (int j = l - 1; j; j--) prb[j] = prb[j - 1] * (1 - p);
            prb[0] = sum * p;
        }
        cout << fixed << setprecision(8) << ans << '\n';
    }
}