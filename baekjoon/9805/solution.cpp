#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double eps = 1e-8;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, b, c, z, y, x;
    cin >> a >> b >> c >> z >> y >> x;
    int xx = b * b + c * c - x * x;
    int yy = a * a + c * c - y * y;
    int zz = a * a + b * b - z * z;
    cout << fixed << setprecision(4) << sqrt(ll(4) * a * a * b * b * c * c - ll(a * a) * xx * xx - ll(b * b) * yy * yy - ll(c * c) * zz * zz + ll(xx) * yy * zz) / 12 + eps << '\n';
}