#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (n == 1) {
            cout << 1 << '\n' << 1 << '\n';
        } else if (k == 1 || k == n) {
            cout << -1 << '\n';
        } else if (k % 2) {
            cout << 5 << '\n';
            cout << 1 << ' ' << 2 << ' ' << k << ' ' << k + 1 << ' ' << k + 2 << '\n';
        } else {
            cout << 3 << '\n';
            cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
        }
    }
}