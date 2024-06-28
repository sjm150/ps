#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    for (int &a: a) cin >> a;
    for (int &b: b) cin >> b;
    for (int &c: c) cin >> c;

    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; i++) ab[i] = {a[i], a[i] - b[i]};
    sort(ab.begin(), ab.end());

    int mind = 1e9;
    vector<pair<int, int>> opt;
    for (auto [a, d]: ab) {
        if (d < mind) {
            opt.emplace_back(a, d);
            mind = d;
        }
    }

    map<int, ll> dp;
    function<ll(int)> calc = [&](int c) {
        auto dit = dp.find(c);
        if (dit != dp.end()) return dit->second;

        auto it = upper_bound(opt.begin(), opt.end(), make_pair(c, int(1e9)));
        if (it == opt.begin()) return 0ll;
        it--;
        ll amt = (c - it->first + it->second) / it->second;
        return dp[c] = amt + calc(c - amt * it->second);
    };

    long long ans = 0;
    for (int c: c) ans += calc(c);
    cout << ans * 2 << '\n';
}