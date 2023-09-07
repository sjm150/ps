#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        c *= 2;
        cout << (abs(a - b) + c - 1) / c << '\n';
    }
}