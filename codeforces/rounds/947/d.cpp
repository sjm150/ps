#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        vector<vector<int>> edges(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int x, y; cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        int ans = 0, m;
        vector<int> path;
        function<bool(int, int)> mdfs = [&](int pre, int cur) {
            if (cur == b) {
                int n = path.size();
                ans += n - n / 2;
                m = path[n / 2];
                return true;
            }
            path.push_back(cur);
            for (int nxt: edges[cur]) {
                if (pre == nxt) continue;
                if (mdfs(cur, nxt)) break;
            }
            path.pop_back();
            return false;
        };
        if (a == b) m = a;
        else mdfs(0, a);

        function<int(int, int)> dfs = [&](int pre, int cur) {
            int d = 0;
            ans++;
            for (int nxt: edges[cur]) {
                if (pre == nxt) continue;
                d = max(d, dfs(cur, nxt) + 1);
                ans++;
            }
            return d;
        };
        int mxd = dfs(0, m);

        cout << ans - mxd - 1 << '\n';
    }
}