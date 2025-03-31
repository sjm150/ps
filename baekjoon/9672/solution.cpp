#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        int n, k; cin >> n >> k;
        if (n == 0) break;
        vector<int> t;
        vector<vector<int>> edges(n);
        for (int i = 0; i < n; i++) {
            int p; cin >> p;
            if (p) edges[p - 1].push_back(i);
            else t.push_back(i);
        }
        vector<bool> s(n, false);
        while (k--) {
            int a; cin >> a;
            s[a - 1] = true;
        }

        vector<int> u(n), d(n);
        function<void(int)> dfs = [&](int cur) {
            int dsum = 0, scnt = 0;
            for (int nxt: edges[cur]) {
                dfs(nxt);
                dsum += d[nxt];
                if (s[nxt]) scnt++;
            }
            u[cur] = d[cur] = dsum;
            if (scnt > 0) d[cur]++;
            if (s[cur]) {
                for (int nxt: edges[cur]) {
                    u[cur] = max(u[cur], dsum - d[nxt] + u[nxt] + 1);
                    int v = dsum - d[nxt] + u[nxt] + 1 + (scnt - s[nxt] > 0);
                    if (d[cur] < v) {
                        d[cur] = v;
                        s[cur] = false;
                    }
                }
            }
        };

        int ans = 0;
        for (int t: t) {
            dfs(t);
            ans += d[t];
        }
        cout << ans << '\n';
    }
}