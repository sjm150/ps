#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int x, t; cin >> x >> t;
    int num = 700 - 8 * x;
    int den = 1200 - 12 * x;
    double cnd = max(double(t) * 5 / 6 * x, double(t) * 2 / 3 * 100);
    if (num * 3 < den && den < num * 6) {
        double s = double(num) / den * t;
        cnd = max(cnd, (s * (600 - 6 * x) / t + 2 * x - 100) * (t - s));
    }
    cout << fixed << setprecision(8) << cnd << '\n';
}