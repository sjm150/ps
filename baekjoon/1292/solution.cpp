#include <iostream>

using namespace std;

int calc(int x) {
    int n = 0;
    for (int i = 1; i * (i + 1) / 2 <= x; i++) n = i;
    return n * (n + 1) * (2 * n + 1) / 6 + (x - n * (n + 1) / 2) * (n + 1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    cout << calc(b) - calc(a - 1) << '\n';
}