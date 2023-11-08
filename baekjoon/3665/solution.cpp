#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<int> t(n), ind(n + 1, 0);
        vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
        for (int i = 0; i < n; i++) cin >> t[i];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ind[t[j]]++;
                adj[t[i]][t[j]] = true;
            }
        }
        int m; cin >> m;
        while (m--) {
            int a, b; cin >> a >> b;
            if (adj[a][b]) {
                ind[a]++, ind[b]--;
                adj[a][b] = false;
                adj[b][a] = true;
            } else {
                ind[b]++, ind[a]--;
                adj[b][a] = false;
                adj[a][b] = true;
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (ind[i] == 0) q.push(i);
        }
        vector<int> ord;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            ord.push_back(cur);
            for (int i = 1; i <= n; i++) {
                if (!adj[cur][i]) continue;
                ind[i]--;
                if (ind[i] == 0) q.push(i);
            }
        }

        if (ord.size() == n) {
            for (int t: ord) cout << t << ' ';
            cout << '\n';
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
}