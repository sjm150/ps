#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    int l = 0, r = n + 1;
    while (l < r) {
        ll m = (l + r) / 2;
        if (m * m < n) l = m + 1;
        else r = m;
    }
    int u = r;

    vector<vector<int>> nums;
    for (int i = 0; i * u < n; i++) {
        nums.emplace_back();
        for (int j = i * u; j < min((i + 1) * u, n); j++) nums.back().push_back(a[j]);
        sort(nums.back().begin(), nums.back().end());
    }

    vector<vector<pair<int, int>>> lev(n + 1);
    for (int k = 1; k <= n; k++) {
        int i = 0, v = 1;
        lev[k].emplace_back(i, v);
        while (i < n) {
            int rem = k;
            int ni = (i + u - 1) / u * u;
            for (; rem && i < ni; i++) {
                if (a[i] >= v) rem--;
            }
            if (rem == 0) {
                lev[k].emplace_back(i, ++v);
                continue;
            }

            for (; i < n; i += u) {
                int cnt = nums[i / u].end() - lower_bound(nums[i / u].begin(), nums[i / u].end(), v);
                if (cnt < rem) rem -= cnt;
                else break;
            }

            for (; rem && i < n; i++) {
                if (a[i] >= v) rem--;
            }
            if (rem == 0) {
                lev[k].emplace_back(i, ++v);
                continue;
            }
        }
    }

    while (q--) {
        int i, x; cin >> i >> x;
        auto it = prev(lower_bound(lev[x].begin(), lev[x].end(), make_pair(i, 0)));
        cout << (it->second <= a[i - 1] ? "YES\n" : "NO\n");
    }
}