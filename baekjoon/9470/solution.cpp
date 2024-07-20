#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int k, m, p; cin >> k >> m >> p;
        vector<vector<int>> edges(m + 1);
        while (p--) {
            int a, b; cin >> a >> b;
            edges[b].push_back(a);
        }
        vector<int> ord(m + 1, -1);
        function<void(int)> dfs = [&](int cur) {
            int mx = 0, cnt = 0;
            for (int nxt: edges[cur]) {
                if (ord[nxt] < 0) dfs(nxt);
                if (ord[nxt] > mx) {
                    mx = ord[nxt];
                    cnt = 1;
                } else if (ord[nxt] == mx) {
                    cnt++;
                }
            }
            ord[cur] = mx + (cnt != 1);
        };
        dfs(m);
        cout << k << ' ' << ord[m] << '\n';
    }
}