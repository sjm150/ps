#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> brd(n);
    for (int i = 0; i < n; i++) cin >> brd[i].first >> brd[i].second;
    sort(brd.begin(), brd.end());

    vector<pair<int, int>> mrg;
    int l = 0, r = brd[0].second;
    for (auto &[li, ri]: brd) {
        if (r < li) {
            mrg.emplace_back(l, r);
            l = li, r = ri;
        } else {
            r = max(r, ri);
        }
    }
    mrg.emplace_back(l, r);

    int ans = 0, rch = 0;
    for (auto &[l, r]: mrg) {
        if (l <= rch) {
            rch = max(rch, 2 * r - l);
            ans = r;
        } else {
            break;
        }
    }

    cout << ans << '\n';
}