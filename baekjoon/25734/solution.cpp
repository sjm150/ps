#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int inf = 1e9 + 2;
    int q;
    cin >> q;

    ll ans = 0;
    set<pair<int, int>> seq;
    seq.emplace(-inf, -inf);
    seq.emplace(inf, inf);

    auto add = [&](int l, int r) {
        ll len = r - l + 1;
        ans += len * (len + 1) / 2;
        seq.emplace(l, r);
    };
    auto del = [&](pair<int, int> p) {
        ll len = p.second - p.first + 1;
        ans -= len * (len + 1) / 2;
        seq.erase(p);
    };

    while (q--) {
        int c, x;
        cin >> c >> x;
        if (c == 1) {
            auto it = seq.upper_bound(make_pair(x, x));
            auto lp = *prev(it), rp = *it;
            int l = x, r = x;
            if (lp.second == x - 1) {
                l = lp.first;
                del(lp);
            }
            if (rp.first == x + 1) {
                r = rp.second;
                del(rp);
            }
            add(l, r);
        } else {
            auto [l, r] = *prev(seq.upper_bound(make_pair(x, inf)));
            del(make_pair(l, r));
            if (l < x) add(l, x - 1);
            if (x < r) add(x + 1, r);
        }
        cout << ans << '\n';
    }
}