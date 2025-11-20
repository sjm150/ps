#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n;
    cin >> n;
    vector<int> l(n);
    for (int &l: l) cin >> l;
    sort(l.begin(), l.end());

    vector<pair<int, int>> lc;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt++;
        if (i == n - 1 || l[i] != l[i + 1]) {
            lc.emplace_back(l[i], cnt);
            cnt = 0;
        }
    }

    unordered_map<int, ll> sum;
    int sz = lc.size();
    for (int i = 0; i < sz; i++) {
        sum[lc[i].first * 2] += ll(lc[i].second / 2) * lc[i].first * lc[i].first;
        for (int j = i + 1; j < sz; j++) sum[lc[i].first + lc[j].first] += ll(min(lc[i].second, lc[j].second)) * lc[i].first * lc[j].first;
    }

    ll ans = 0;
    for (auto [l, a]: sum) ans = max(ans, a);
    cout << ans << '\n';
}