#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int x, y, d, t; cin >> x >> y >> d >> t;

    double dst = sqrt(x * x + y * y);
    int q = int(dst) / d;
    double r = dst - q * d;

    double mint = min(dst, min(q * t + r, (q + 1) * t + d - r));
    if (q > 0) mint = min(mint, double((q + 1) * t));
    else mint = min(mint, double(2 * t));

    cout << fixed << setprecision(10) << mint << '\n';
}