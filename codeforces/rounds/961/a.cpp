#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int ans = 0;
        if (k == 0) {
            cout << 0 << '\n';
            continue;
        } else {
            ans++;
            k = max(0, k - n);
        }
        for (int i = n - 1; i && k > 0; i--) {
            for (int j = 0; j < 2 && k; j++) {
                ans++;
                k = max(0, k - i);
            }
        }
        cout << ans << '\n';
    }
}