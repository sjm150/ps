#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> fb(n, vector<int>(2)), edges(n);
    for (auto &fb: fb) cin >> fb[0];
    for (auto &fb: fb) cin >> fb[1];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<vector<int>> cnt(n, vector<int>(2, 0));
    function<void(int, int)> dfs = [&](int pre, int cur) {
        for (int nxt: edges[cur]) {
            if (pre == nxt) continue;
            dfs(cur, nxt);
            cnt[cur][0] += cnt[nxt][0];
            cnt[cur][1] += cnt[nxt][1];
        }
        if (fb[cur][0] > fb[cur][1]) {
            cnt[cur][1] = cnt[cur][0] + 1;
        } else if (fb[cur][0] < fb[cur][1]) {
            cnt[cur][0] = cnt[cur][1] + 1;
        } else {
            vector<int> mn(2);
            mn[0] = min(cnt[cur][0], cnt[cur][1] + 1);
            mn[1] = min(cnt[cur][0] + 1, cnt[cur][1]);
            cnt[cur] = mn;
        }
    };
    dfs(-1, 0);

    int sum = 0;
    for (auto &fb: fb) sum += max(fb[0], fb[1]);
    cout << sum << ' ' << cnt[0][0] << '\n';
}