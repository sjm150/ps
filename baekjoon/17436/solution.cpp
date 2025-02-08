#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n; cin >> n;
    ll m; cin >> m;
    vector<int> p(n);
    for (int &p: p) cin >> p;
    function<ll(int, ll)> cnt = [&](int idx, ll cur) {
        if (idx == n) return 0ll;
        ll nxt = cur * p[idx];
        return m / nxt -  cnt(idx + 1, nxt) + cnt(idx + 1, cur);
    };
    cout << cnt(0, 1) << '\n';
}