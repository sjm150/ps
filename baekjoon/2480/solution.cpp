#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    if (n1 == n2 && n2 == n3) {
        cout << 10000 + n1 * 1000 << '\n';
    } else if (n1 == n2) {
        cout << 1000 + n1 * 100 << '\n';
    } else if (n2 == n3) {
        cout << 1000 + n2 * 100 << '\n';
    } else if (n3 == n1) {
        cout << 1000 + n3 * 100 << '\n';
    } else {
        cout << max(n1, max(n2, n3)) * 100 << '\n';
    }
}