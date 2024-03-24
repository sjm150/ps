#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        int ans = 1;
        for (int i = b; b; b /= 2) {
            if (b & 1) ans = ans * a % 10;
            a = a * a % 10;
        }
        ans %= 10;
        if (ans == 0) ans = 10;
        cout << ans << '\n';
    }
}