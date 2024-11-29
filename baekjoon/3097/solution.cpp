#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    int xsum = accumulate(x.begin(), x.end(), 0);
    int ysum = accumulate(y.begin(), y.end(), 0);
    double ans = 1e9;
    for (int i = 0; i < n; i++) {
        xsum -= x[i];
        ysum -= y[i];
        ans = min(ans, sqrt(xsum * xsum + ysum * ysum));
        xsum += x[i];
        ysum += y[i];
    }
    cout << xsum << ' ' << ysum << '\n';
    cout << fixed << setprecision(2) << ans << '\n';
}