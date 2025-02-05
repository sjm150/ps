#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, x, b, y, t; cin >> a >> x >> b >> y >> t;
    cout << a + 21 * x * max(0, t - 30) << ' ' << b + 21 * y * max(0, t - 45) << '\n';
}