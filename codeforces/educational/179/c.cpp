#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        ll len = 1, ans = 1e18;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] == a[i]) {
                len++;
            } else {
                ans = min(ans, (n - len) * a[i - 1]);
                len = 1;
            }
        }
        ans = min(ans, (n - len) * a[n - 1]);
        cout << ans << '\n';
    }
}