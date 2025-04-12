#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> vw(n);
    multiset<int> s;
    for (auto &[v, w]: vw) cin >> w >> v;
    while (m--) {
        int x; cin >> x;
        s.insert(x);
    }
    sort(vw.begin(), vw.end(), greater<pair<int, int>>());
    long long ans = 0;
    for (auto [v, w]: vw) {
        auto it = s.lower_bound(w);
        if (it != s.end()) {
            ans += v;
            s.erase(it);
        }
    }
    cout << ans << '\n';
}