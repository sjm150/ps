#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cout.setf(ios::fixed);
    cout.precision(3);
    double x1, y1, r1; cin >> x1 >> y1 >> r1;
    double x2, y2, r2; cin >> x2 >> y2 >> r2;

    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (d <= abs(r1 - r2)) {
        cout << pi * min(r1, r2) * min(r1, r2) << '\n';
        return 0;
    } else if (d >= r1 + r2) {
        cout << 0.0 << '\n';
        return 0;
    }

    double a1 = acos((r1 * r1 + d * d - r2 * r2) / 2 / r1 / d);
    double a2 = acos((r2 * r2 + d * d - r1 * r1) / 2 / r2 / d);

    cout << a1 * r1 * r1 + a2 * r2 * r2 - r1 * r1 * sin(a1) * cos(a1) - r2 * r2 * sin(a2) * cos(a2) << '\n';
}