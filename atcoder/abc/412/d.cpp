#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> adj(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = adj[b][a] = true;
    }

    int mx = 0;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    do {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (i == p[i] || i == p[p[i]]) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        int cnt = 0;
        for (int i = 0; i < n; i++) cnt += adj[i][p[i]];
        mx = max(mx, cnt);
    } while (next_permutation(p.begin(), p.end()));

    cout << m + n - 2 * mx << '\n';
}