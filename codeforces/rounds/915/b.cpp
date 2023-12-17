#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> edges(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (edges[i].size() == 1) cnt++;
        }

        cout << (cnt + 1) / 2 << '\n';
    }
}