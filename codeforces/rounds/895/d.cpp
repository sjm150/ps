#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(int a, int b) {
    return ll(a) / gcd(a, b) * b;
}

ll sigma(int a, int b) {
    if (a > b) return 0;
    return (ll(a) + b) * (b - a + 1) / 2;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x, y; cin >> n >> x >> y;
        int xycnt = n / lcm(x, y);
        int xcnt = n / x - xycnt;
        int ycnt = n / y - xycnt;
        cout << sigma(n - xcnt + 1, n) - sigma(1, ycnt) << '\n';
    }
}