#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    function<int(int, int)> gcd = [&](int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int g = gcd(a, b);
        cout << a / g * b << ' ' << g << '\n';
    }
}