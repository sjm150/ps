#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> g(n);
        for (auto &g: g) cin >> g;
        vector<vector<int>> edges(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (g[i][j] == '0') edges[j].push_back(i);
                else edges[i].push_back(j);
            }
        }
        vector<bool> vst(n, false);
        vector<int> ans(n);
        int idx = n - 1;
        function<void(int)> dfs = [&](int cur) {
            vst[cur] = true;
            for (int nxt: edges[cur]) {
                if (!vst[nxt] && g[cur][nxt] == '1') dfs(nxt);
            }
            ans[idx--] = cur + 1;
        };
        for (int i = 0; i < n; i++) {
            if (!vst[i]) dfs(i);
        }
        for (int a: ans) cout << a << ' ';
        cout << '\n';
    }
}