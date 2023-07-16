#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        x--, y--;
        int g = gcd(m, n);
        if (abs(x - y) % g != 0) {
            cout << -1 << '\n';
            continue;
        }
        int res = -1;
        for (int i = x; i < m / g * n; i += m) {
            if (i % n == y) {
                res = i + 1;
                break;
            }
        }
        cout << res << '\n';
    }
}