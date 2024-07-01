#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, t; cin >> n >> t;
    vector<tuple<double, double, int>> xyt(n);
    for (auto &[x, y, t]: xyt) cin >> x >> y >> t;

    auto dst = [](double x0, double y0, double x1, double y1) {
        return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
    };

    double px = get<0>(xyt[0]), py = get<1>(xyt[0]);
    double d = 0, r = 0;
    for (int i = 1; i < n; i++) {
        auto &[x0, y0, t0] = xyt[i - 1];
        auto &[x1, y1, t1] = xyt[i];
        d += dst(x0, y0, x1, y1);
        for (int tt = (t0 + t - 1) / t * t; tt <= t1; tt += t) {
            double cx = (x0 * (t1 - tt) + x1 * (tt - t0)) / (t1 - t0);
            double cy = (y0 * (t1 - tt) + y1 * (tt - t0)) / (t1 - t0);
            r += dst(px, py, cx, cy);
            px = cx, py = cy;
        }
    }
    r += dst(px, py, get<0>(xyt.back()), get<1>(xyt.back()));

    cout << fixed << setprecision(14) << (d - r) / d * 100 << '\n';
}