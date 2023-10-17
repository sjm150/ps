#include <bits/stdc++.h>
using namespace std;

int res[21][21][21];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    int& cache = res[a][b][c];
    if (cache) return cache;
    if (a < b && b < c) return cache = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else return cache = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    while (true) {
        int a, b, c; cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        cout << w(a, b, c) << '\n';
    }
}