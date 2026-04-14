#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int a, b;
    cin >> a >> b;
    a--, b--;

    vector<int> pth;
    function<bool(int, int)> mdfs = [&](int pre, int cur) {
        pth.push_back(cur);
        if (cur == b) return true;
        for (int nxt: edges[cur]) {
            if (nxt == pre) continue;
            if (mdfs(cur, nxt)) return true;
        }
        pth.pop_back();
        return false;
    };
    mdfs(-1, a);

    int md = (pth.size() + 1) / 2;
    int blk = pth[md - 1], r = pth[md];
    vector<bool> used(n, false);
    for (int i = md; i < int(pth.size()); i++) used[pth[i]] = true;

    int ans = 0;
    function<void(int, int, int)> dfs = [&](int pre, int cur, int cnt) {
        if (!used[cur]) cnt++;
        ans = max(ans, cnt);
        for (int nxt: edges[cur]) {
            if (nxt == pre || nxt == blk) continue;
            dfs(cur, nxt, cnt);
        }
        if (!used[cur]) cnt--;
    };
    dfs(-1, r, accumulate(used.begin(), used.end(), 0));
    cout << ans << '\n';
}