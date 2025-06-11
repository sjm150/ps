#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int b, c;
    cin >> b >> c;
    int x = b * b - c;
    int s = round(sqrt(x));
    while (s * s < x) s++;
    while (s * s > x) s--;
    if (s) cout << -b - s << ' ' << -b + s << '\n';
    else cout << -b << '\n';
}