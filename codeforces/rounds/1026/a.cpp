#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());
        int l = 0, r = n - 1;
        while (l < r && a[l] % 2 == 0) l++;
        while (l < r && a[r] % 2 == 0) r--;
        int ans = n - 1 - r + l;
        l = 0, r = n - 1;
        while (l < r && a[l] % 2 == 1) l++;
        while (l < r && a[r] % 2 == 1) r--;
        ans = min(ans, n - 1 - r + l);
        cout << ans << '\n';
    }
}