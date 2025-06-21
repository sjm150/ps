#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n;
        ll m;
        cin >> n >> m;
        if (n * ll(n + 1) / 2 < m || m < n) {
            cout << -1 << '\n';
            continue;
        }

        int r = -1;
        vector<pair<int, int>> ans;
        if (m < 2 * n) {
            r = m - n + 1;
            if (r != 1) ans.emplace_back(r, 1);
            for (int i = 2; i <= n; i++) {
                if (i != r) ans.emplace_back(1, i);
            }
        } else {
            r = n;
            if (r != 1) ans.emplace_back(r, 1);
            ll rem = n * ll(n + 1) / 2;
            for (int i = n - 1; i > 1; i--) {
                if (rem - m < i - 1) {
                    ans.emplace_back(r, i);
                } else {
                    rem -= i - 1;
                    ans.emplace_back(1, i);
                }
            }
        }

        assert(r != -1);
        assert(int(ans.size()) == n - 1);
        cout << r << '\n';
        for (auto [u, v]: ans) cout << u << ' ' << v << '\n';
    }
}