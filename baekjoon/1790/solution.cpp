#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int base = 0;
    int len = 1;
    for (int i = 9; i * len < k; i *= 10) {
        base += i;
        k -= i * len;
        len++;
    }
    base += (k + len - 1) / len;
    if (base > n) {
        cout << -1 << '\n';
        return 0;
    }
    int p = len - 1 - (k - 1) % len;
    while (p--) base /= 10;
    cout << base % 10 << '\n';
}