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
        int ans = 0;
        for (int l = 0, r = n - 1; l < r; l++, r--) {
            if (a[l] == a[r]) break;
            ans++;
        }
        cout << ans << '\n';
    }
}