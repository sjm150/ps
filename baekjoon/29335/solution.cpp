#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int inf = 1e9 + 1;
    int q;
    cin >> q;
    set<pair<int, int>> xy;
    xy.emplace(0, inf);
    xy.emplace(inf, 0);
    ll sum = 0;
    while (q--) {
        int x, y;
        cin >> x >> y;
        auto it = prev(xy.lower_bound(make_pair(x, y)));
        if (next(it)->second >= y) {
            cout << sum << '\n';
            continue;
        }
        while (it->second <= y) {
            sum -= ll(it->first - prev(it)->first) * (it->second - next(it)->second);
            it = prev(xy.erase(it));
        }
        sum += ll(x - it->first) * (y - next(it)->second);
        xy.emplace(x, y);
        cout << sum << '\n';
    }
}