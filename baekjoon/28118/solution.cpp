#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> conn(n, vector<bool>(n, false));
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        conn[a][b] = conn[b][a] = true;
    }

    vector<bool> vst(n, false);
    function<void(int)> dfs = [&](int cur) {
        vst[cur] = true;
        for (int i = 0; i < n; i++) {
            if (conn[cur][i] && !vst[i]) dfs(i);
        }
    };

    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (vst[i]) continue;
        dfs(i);
        ans++;
    }
    cout << ans << '\n';
}