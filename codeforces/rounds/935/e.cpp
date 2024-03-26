#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> p(n);
        for (int &p: p) cin >> p;

        vector<bool> tch(n, false);
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            tch[m] = true;
            if (p[m] <= x) l = m;
            else r = m;
        }

        if (p[l] == x) {
            cout << 0 << '\n';
            continue;
        }

        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] == x) {
                idx = i;
                break;
            }
        }

        vector<pair<int, int>> ans;
        ans.emplace_back(idx + 1, l + 1);
        if (tch[idx]) {
            for (int i = 0; i < n; i++) {
                if (!tch[i] && p[i] < x) {
                    ans.emplace_back(idx + 1, i + 1);
                    break;
                }
            }
        }

        cout << ans.size() << '\n';
        for (auto &[i, j]: ans) cout << i << ' ' << j << '\n';
    }
}