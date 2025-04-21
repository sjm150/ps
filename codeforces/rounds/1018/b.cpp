#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> l(n), r(n);
        for (int &l: l) cin >> l;
        for (int &r: r) cin >> r;

        long long ans = 1;
        vector<int> mn(n);
        for (int i = 0; i < n; i++) {
            ans += max(l[i], r[i]);
            mn[i] = min(l[i], r[i]);
        }
        sort(mn.begin(), mn.end(), greater<int>());
        for (int i = 0; i < k - 1; i++) ans += mn[i];

        cout << ans << '\n';
    }
}