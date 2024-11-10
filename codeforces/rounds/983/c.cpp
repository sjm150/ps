#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());
        int ans = n;
        for (int i = 0; i < n - 1; i++) ans = min(ans, i + int(a.end() - lower_bound(a.begin(), a.end(), a[i] + a[i + 1])));
        cout << ans << '\n';
    }
}