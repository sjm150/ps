#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    long long xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    if ((xa + ya + xb + yb) % 2) {
        cout << -1 << '\n';
    } else {
        bool odd = (xa + xb) % 2;
        if ((xa < xb) == (ya < yb)) cout << (xa + xb - odd) / 2 << ' ' << (ya + yb + odd) / 2 << '\n';
        else cout << (xa + xb + odd) / 2 << ' ' << (ya + yb + odd) / 2 << '\n';
    }
}