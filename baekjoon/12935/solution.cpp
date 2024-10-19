#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int s; cin >> s;
    int l = 1, r = 101;
    while (l < r) {
        int m = (l + r) / 2;
        if (m * (m - 1) <= s) l = m + 1;
        else r = m;
    }
    l--;
    r = s - l * (l - 1);
    cout << 1 + 2 * l + r << '\n';
    for (int i = 1; i <= l; i++) {
        cout << 0 << ' ' << 2 * i - 1 << '\n';
        cout << 2 * i - 1 << ' ' << 2 * i << '\n';
    }
    for (int i = 1; i <= r; i++) cout << 2 << ' ' << 2 * l + i << '\n';
}