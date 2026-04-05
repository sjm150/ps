#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int tc = 1;; tc++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) break;
        cout << "Triangle #" << tc << '\n';
        auto prnt = [&](int x) { cout << fixed << setprecision(3) << sqrt(x) << "\n\n"; };
        if (a < 0) {
            if (b < c) cout << "a = ", prnt(c * c - b * b);
            else cout << "Impossible.\n\n";
        } else if (b < 0) {
            if (a < c) cout << "b = ", prnt(c * c - a * a);
            else cout << "Impossible.\n\n";
        } else {
            cout << "c = ";
            prnt(a * a + b * b);
        }
    }
}