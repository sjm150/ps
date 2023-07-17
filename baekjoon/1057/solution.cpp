#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    for (int i = 1; ; i++) {
        x /= 2, y /= 2;
        if (x == y) {
            cout << i << '\n';
            return 0;
        }
    }
}