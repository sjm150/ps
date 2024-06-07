#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int ans = 1e9 + 5;
        for (int i = 1; i < n; i++) {
            ans = min(ans, max(a[i - 1], a[i]) - 1);
        }
        cout << ans << '\n';
    }
}