#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, t, w; cin >> n >> t >> w;
    queue<pair<int, int>> q;
    while (n--) {
        int p, t; cin >> p >> t;
        q.emplace(p, t);
    }
    int m; cin >> m;
    vector<tuple<int, int, int>> ext;
    while (m--) {
        int p, t, c; cin >> p >> t >> c;
        ext.emplace_back(c, p, t);
    }
    sort(ext.begin(), ext.end());

    int cur = 0, eidx = 0;
    while (cur < w) {
        auto [p, r] = q.front(); q.pop();
        if (r > t && cur + t < w) {
            for (int i = 0; i < t; i++) cout << p << '\n';
            cur += t;
            r -= t;
        } else {
            int tt = min(r, w - cur);
            for (int i = 0; i < tt; i++) cout << p << '\n';
            cur += tt;
            r -= tt;
        }
        while (eidx < ext.size() && get<0>(ext[eidx]) <= cur) {
            auto &[c, p, t] = ext[eidx++];
            q.emplace(p, t);
        }
        if (r) q.emplace(p, r);
    }
}