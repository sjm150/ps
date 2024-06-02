#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int b, c, h;
        cin >> b >> c >> h;
        cout << min(2 * b - 1, 2 * (c + h) + 1) << '\n';
    }
}