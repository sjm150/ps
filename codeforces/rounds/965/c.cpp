#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int m = n / 2 - 1;
        vector<pair<int, int>> ab(n);
        for (auto &[a, b]: ab) cin >> a;
        for (auto &[a, b]: ab) cin >> b;
        sort(ab.begin(), ab.end());

        ll ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (ab[i].second) {
                ans = ll(ab[i].first) + ab[i > m ? m : m + 1].first + k;
                break;
            }
        }

        int l = 0, r = 2e9 + 1;
        while (l < r) {
            int m = (ll(l) + r) / 2;
            int cnt = 0, rem = k;
            for (int i = n - 2; i >= 0; i--) {
                if (ab[i].first >= m) {
                    cnt++;
                    continue;
                }
                if (ab[i].second) {
                    if (rem < m - ab[i].first) {
                        break;
                    } else {
                        rem -= m - ab[i].first;
                        cnt++;
                    }
                }
            }
            if (cnt * 2 > n - 1) l = m + 1;
            else r = m;
        }

        cout << max(ans, ll(ab.back().first) + r - 1) << '\n';
    }
}