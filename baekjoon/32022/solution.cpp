#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<double, double> pd;
    const double eps = 1e-7;
    auto dst = [&](pd o, pd a, pd b) {
        double vx = a.first - b.first, vy = a.second - b.second;
        if (abs(vx) < eps) return abs(o.first - a.first);
        if (abs(vy) < eps) return abs(o.second - a.second);
        double x = (o.first * vx / vy + o.second + a.first * vy / vx - a.second) / (vy / vx + vx / vy);
        double y = (x - a.first) * vy / vx + a.second;
        return sqrt((o.first - x) * (o.first - x) + (o.second - y) * (o.second - y));
    };
    int n; cin >> n;
    vector<pd> xy(n);
    for (auto &[x, y]: xy) cin >> x >> y;
    double ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dst(xy[i], xy[0], xy[n - 1]));
    for (int i = 1; i < n; i++) {
        double mx = 0;
        for (int j = 0; j < n; j++) mx = max(mx, dst(xy[j], xy[i - 1], xy[i]));
        ans = min(ans, mx);
    }
    cout << setprecision(3) << fixed << ans << '\n';
}