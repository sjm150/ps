#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    function<int(int, int)> gcd = [&](int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    int ab;
    while (cin >> ab) {
        int ac, bd;
        cin >> ac >> bd;
        int num = ab * ac, den = bd - ac;
        int g = gcd(num, den);
        cout << num / g << '/' << den / g << '\n';
    }
}