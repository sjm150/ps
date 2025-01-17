#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        double n; cin >> n;
        string op;
        getline(cin, op);
        istringstream in(op);
        char c;
        while (in >> c) {
            if (c == '@') n *= 3;
            else if (c == '%') n += 5;
            else n -= 7;
        }
        cout << fixed << setprecision(2) << n << '\n';
    }
}