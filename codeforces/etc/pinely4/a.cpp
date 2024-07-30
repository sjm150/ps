#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int ans = 0;
        for (int i = 0; i < n; i += 2) ans = max(ans, a[i]);
        cout << ans << '\n';
    }
}