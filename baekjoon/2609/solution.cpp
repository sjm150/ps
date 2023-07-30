#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int a, b; cin >> a >> b;
    int g = gcd(a, b);
    cout << g << '\n';
    cout << a / g * b << '\n';
}