#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> x(n);
    for (int &x: x) cin >> x;
    if (n == 1) {
        cout << "A\n";
    } else if (n == 2) {
        if (x[0] == x[1]) cout << x[0] << '\n';
        else cout << "A\n";
    } else {
        int c = x[2] - x[1], d = x[1] - x[0];
        if (d == 0) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (x[0] != x[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) cout << x[0] << '\n';
            else cout << "B\n";
        } else if (c % d) {
            cout << "B\n";
        } else {
            int a = c / d;
            int b = x[1] - a * x[0];
            bool ok = true;
            for (int i = 1; i < n; i++) {
                if (a * x[i - 1] + b != x[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) cout << a * x[n - 1] + b << '\n';
            else cout << "B\n";
        }
    }
}