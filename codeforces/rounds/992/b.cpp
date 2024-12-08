#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ans = 0;
        for (; n > 2; n = (n - 1) / 2) ans++;
        cout << ans + n << '\n';
    }
}