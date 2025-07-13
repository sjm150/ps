#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int ans = n == 0;
        for (int i = n; i <= m; i++) {
            for (int j = i; j; j /= 10) ans += j % 10 == 0;
        }
        cout << ans << '\n';
    }
}