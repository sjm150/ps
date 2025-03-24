#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, h; cin >> n >> h;
    int r = 0;
    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0; i < n; i++) {
        int p, d; cin >> p >> d;
        if (p) edges[p - 1].emplace_back(d, i);
        else r = i;
    }

    vector<int> dst(n, 0);
    function<void(int)> dfs = [&](int cur) {
        for (auto [d, nxt]: edges[cur]) {
            dfs(nxt);
            dst[cur] = max(dst[cur], dst[nxt] + d);
        }
    };
    dfs(r);

    int ans = 0;
    function<void(int, int)> dfs2 = [&](int cur, int sum) {
        if (dst[cur] + sum > h) {
            int x = min(dst[cur] + sum - h, sum);
            ans += x;
            sum -= x;
        }
        for (auto [d, nxt]: edges[cur]) dfs2(nxt, sum + d);
    };
    dfs2(r, 0);
    cout << ans << '\n';
}