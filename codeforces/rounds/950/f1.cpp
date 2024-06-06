#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> r(k), c(k);
        for (int i = 0; i < k; i++) cin >> r[i] >> c[i];

        map<int, int> bots;
        for (int i = 0; i < k; i++) {
            auto it = bots.find(c[i]);
            if (it == bots.end()) {
                bots[c[i]] = i;
            } else if (r[it->second] < r[i]) {
                it->second = i;
            }
        }

        vector<bool> lb(k, false);
        int pre = 1, mxr = 0;
        ll ans = 0;
        for (auto &[col, i]: bots) {
            ans += ll(col - pre) * (n - mxr);
            if (mxr < r[i]) {
                mxr = r[i];
                lb[i] = true;
            }
            pre = col;
        }
        ans += ll(m + 1 - pre) * (n - mxr);

        cout << ans << '\n';
        for (int i = 0; i < k; i++) cout << (lb[i] ? 1 : 0) << ' ';
        cout << '\n';
    }
}