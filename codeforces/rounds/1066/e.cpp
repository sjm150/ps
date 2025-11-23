#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        int sz = 3 * n + 1;
        vector<int> cnt(sz, 0);
        for (int a: a) cnt[a]++;

        int ans = 0, st = -1;
        for (int i = 1; i < sz - 1; i++) {
            if (cnt[i] > k) {
                cnt[i + 1] += cnt[i] - 1;
                if (st < 0) st = i;
            } else {
                if (st >= 0) {
                    ans = max(ans, i - st);
                    st = -1;
                }
            }
        }
        cout << ans << '\n';
    }
}