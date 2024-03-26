#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        if ((3 - b % 3) % 3 > c) cout << -1 << '\n';
        else cout << a + (b + c + 2) / 3 << '\n';
    }
}