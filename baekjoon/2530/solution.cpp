#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, b, c, d; cin >> a >> b >> c >> d;
    c += d % 60;
    d /= 60;
    b += c / 60;
    c %= 60;
    b += d % 60;
    d /= 60;
    a += b / 60;
    b %= 60;
    a = (a + d) % 24;
    cout << a << ' ' << b << ' ' << c << '\n';
}