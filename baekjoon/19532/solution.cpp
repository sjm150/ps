#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << (c * e - b * f) / (a * e - b * d) << ' ' << (c * d - a * f) / (b * d - a * e) << '\n';
}