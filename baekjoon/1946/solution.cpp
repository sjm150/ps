#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> lr(n);
        for (auto &[l, r]: lr) cin >> l >> r;
        sort(lr.begin(), lr.end());
        int ans = 0, mn = n + 1;
        for (auto [_, r]: lr) {
            if (mn > r) {
                mn = r;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}