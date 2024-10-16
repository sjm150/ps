#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, c; cin >> n >> m >> c;
    int mn = (n + m - 1) / m * m - n;
    int mm = (n + m - 1) / m, cc = 0;
    for (int i = 0; i * m <= n; i++) {
        int r = (n - i * m) % c;
        if (mn > r) {
            mn = r;
            mm = i, cc = (n - i * m) / c;
        }
        if (mn > c - r) {
            mn = c - r;
            mm = i, cc = (n - i * m + c - 1) / c;
        }
    }
    cout << mm << ' ' << cc << '\n';
}