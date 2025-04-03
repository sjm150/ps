#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<double, double>> xy(n);
    for (auto &[x, y]: xy) cin >> x >> y;
    int m; cin >> m;
    while (m--) {
        int p; cin >> p;
        vector<int> r(p);
        for (int &r: r) cin >> r;
        double ans = 0;
        auto sqr = [&](double x) { return x * x; };
        for (int i = 1; i < p; i++) {
            ans += sqrt(sqr(xy[r[i]].first - xy[r[i - 1]].first) + sqr(xy[r[i]].second - xy[r[i - 1]].second));
        }
        cout << int(ans + 0.5) << '\n';
    }
}