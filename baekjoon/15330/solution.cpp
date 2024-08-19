#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m; cin >> m;
    vector<pi> xy(m);
    for (auto &[x, y]: xy) cin >> x >> y;
    int ans = 0;
    vector<pi> ps;
    function<int(int, int)> gcd = [&](int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    auto chk = [&]() {
        map<pi, int> cnt;
        for (auto &[i, j]: ps) {
            int dx = xy[i].first - xy[j].first;
            int dy = xy[i].second - xy[j].second;
            if (dx < 0) dx = -dx, dy = -dy;
            int g = gcd(dx, dy);
            dx /= g, dy /= g;
            cnt[make_pair(dx, dy)]++;
        }
        int cur = 0;
        for (auto &[p, c]: cnt) cur += c * (c - 1) / 2;
        ans = max(ans, cur);
    };
    vector<bool> sel(m, false);
    function<void(int)> dfs = [&](int idx) {
        if (idx == m) {
            chk();
            return;
        }
        if (sel[idx]) {
            dfs(idx + 1);
            return;
        }
        for (int i = idx + 1; i < m; i++) {
            if (sel[i]) continue;
            sel[i] = true;
            ps.emplace_back(idx, i);
            dfs(idx + 1);
            ps.pop_back();
            sel[i] = false;
        }
    };
    dfs(0);
    cout << ans << '\n';
}