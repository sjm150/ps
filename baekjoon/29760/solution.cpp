#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, h, w;
    cin >> n >> h >> w;
    map<int, pair<int, int>> mnx;
    mnx[0] = {1, 1};
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (mnx.find(x) == mnx.end()) {
            mnx[x] = {y, y};
        } else {
            mnx[x].first = min(mnx[x].first, y);
            mnx[x].second = max(mnx[x].second, y);
        }
    }
    int plv = 0, prv = 0;
    for (auto it = next(mnx.begin()); it != mnx.end(); it++) {
        auto [pl, pr] = prev(it)->second;
        auto [l, r] = it->second;
        int lv = min(abs(r - pl) + plv, abs(r - pr) + prv) + r - l;
        int rv = min(abs(l - pl) + plv, abs(l - pr) + prv) + r - l;
        swap(lv, plv);
        swap(rv, prv);
    }
    cout << min(plv, prv) + (prev(mnx.end())->first - 1) * 100 << '\n';
}