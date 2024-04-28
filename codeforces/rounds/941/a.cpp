#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> cnt(101, 0);
        int r = 0;
        for (int i = 0; i < n; i++) {
            int c; cin >> c;
            cnt[c]++;
            if (cnt[c] == k) {
                cnt[c] = 0;
                r += k - 1;
            }
        }

        for (int &c: cnt) {
            if (c && c + r >= k) {
                r += c - 1;
                c = 0;
            }
        }

        int ans = min(k - 1, r);
        for (int c: cnt) ans += c;
        cout << ans << '\n';
    }
}