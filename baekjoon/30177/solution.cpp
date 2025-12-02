#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].emplace_back(b);
        edges[b].emplace_back(a);
    }

    vector<bool> odd(n), leaf(n, false);
    vector<int> dst(n, 1e9), lf, d1;
    function<void(int, int, bool)> dfs = [&](int pre, int cur, bool o) {
        odd[cur] = o;
        for (int nxt: edges[cur]) {
            if (nxt == pre) continue;
            dfs(cur, nxt, !o);
            dst[cur] = min(dst[cur], dst[nxt] + 1);
        }
        if (edges[cur].size() == 1) {
            leaf[cur] = true;
            lf.push_back(cur);
            dst[cur] = 0;
        }
        if (dst[cur] == 1) d1.push_back(cur);
    };
    int r = 0;
    while (edges[r].size() == 1) r++;
    dfs(-1, r, false);

    int sz = lf.size();
    bool same = true;
    for (int i = 0; i < sz; i++) {
        if (odd[lf[0]] != odd[lf[i]]) {
            same = false;
            break;
        }
    }

    int mx = n - 1;
    for (int v: d1) {
        int cnt = 0;
        for (int nxt: edges[v]) cnt += leaf[nxt];
        assert(cnt > 0);
        mx -= cnt - 1;
    }

    cout << (same ? 1 : 3) << ' ' << mx << '\n';
}