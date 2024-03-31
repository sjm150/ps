#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (k == 1) {
            for (int i = 1; i <= n; i++) cout << i << ' ';
            cout << '\n';
        } else if (k == n) {
            for (int i = 0; i < n; i++) cout << 1 << ' ';
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}