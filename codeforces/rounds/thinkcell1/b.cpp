#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            if (i & 1) cout << n - i / 2 << ' ';
            else cout << i / 2 + 1 << ' ';
        }
        cout << '\n';
    }
}