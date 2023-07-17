#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int s = sqrt(y - x);
        cout << 2 * s - 1 + (y - x - s * s + s - 1) / s << '\n';
    }
}