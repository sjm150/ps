#include <iostream>

using namespace std;

int order(int r, int c, int n) {
    if (n == 1) return r * 2 + c;
    int divn = (1 << (n - 1));
    return divn * divn * (r / divn * 2 + c / divn) + order(r % divn, c % divn, n - 1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, r, c;
    cin >> n >> r >> c;
    cout << order(r, c, n) << '\n';
}