#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, r; cin >> n >> r;
    vector<vector<pair<int, int>>> edges(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, d; cin >> a >> b >> d;
        edges[a].emplace_back(d, b);
        edges[b].emplace_back(d, a);
    }

    int stmd = 0, maxd = 0;
    function<void(int, int, bool, int)> dfs = [&](int pre, int cur, bool stm, int dst) {
        if (stm) stmd = max(stmd, dst);
        maxd = max(maxd, dst);
        int cnt = 0;
        for (auto &[d, nxt]: edges[cur]) {
            if (nxt != pre) cnt++;
        }
        if (cnt > 1) stm = false;
        for (auto &[d, nxt]: edges[cur]) {
            if (nxt != pre) dfs(cur, nxt, stm, dst + d);
        }
    };

    dfs(0, r, true, 0);
    cout << stmd << ' ' << maxd - stmd << '\n';
}