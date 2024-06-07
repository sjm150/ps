#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        int ans = 1;
        while ((x & ans) == (y & ans)) ans *= 2;
        cout << ans << '\n';
    }
}