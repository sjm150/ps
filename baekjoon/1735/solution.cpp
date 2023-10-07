#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a1, b1; cin >> a1 >> b1;
    int a2, b2; cin >> a2 >> b2;
    int g = gcd(b1, b2);
    int num = b2 / g * a1 + b1 / g * a2;
    int den = b1 / g * b2;
    g = gcd(num, den);
    cout << num / g << ' ' << den / g << '\n';
}