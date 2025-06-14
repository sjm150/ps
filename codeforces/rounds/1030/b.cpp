#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << 2 * n - 1 << '\n';
        cout << 1 << ' ' << 1 << ' ' << n << '\n';
        for (int i = 1; i < n; i++) {
            cout << i + 1 << ' ' << 1 << ' ' << i << '\n';
            cout << i + 1 << ' ' << i + 1 << ' ' << n << '\n';
        }
    }
}