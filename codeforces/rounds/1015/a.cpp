#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n % 2) {
            cout << n << ' ';
            for (int i = 1; i < n; i++) cout << i << ' ';
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}