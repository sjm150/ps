#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    const int mod = 998244353;
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &a: a) {
        for (int &a: a) cin >> a;
    }
    vector<pair<int, int>> qs(q);
    for (auto &[c, i]: qs) cin >> c >> i;

    int lst = q - 1;
    while (lst >= 0 && qs[lst].first == 2) lst--;

    auto solve = [&]() {
        if (lst < 0) return 1;

        vector<int> g(n, 0);
        for (int j = lst; j < q; j++) {
            int k = qs[j].second - 1;
            map<pi, int> grp;
            for (int i = 0; i < n; i++) {
                pi cur = {g[i], a[i][k]};
                if (grp.find(cur) == grp.end()) grp[cur] = grp.size();
            }
            for (int i = 0; i < n; i++) g[i] = grp[{g[i], a[i][k]}];
        }

        map<int, int> cnt;
        for (int g: g) cnt[g]++;
        long long ans = 1;
        for (auto [g, cnt]: cnt) {
            for (int i = 2; i <= cnt; i++) ans = ans * i % mod;
        }
        return int(ans);
    };

    cout << solve() << '\n';
}