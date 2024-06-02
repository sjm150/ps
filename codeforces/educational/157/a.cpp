#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int x, y, k; cin >> x >> y >> k;
        if (x >= y) cout << x << '\n';
        else cout << y + max(0, y - x - k) << '\n';
    }
}