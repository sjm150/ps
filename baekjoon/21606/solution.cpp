#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<bool> ind;
vector<vector<int>> edges;
ll ans;

ll dfs(int pre, int cur) {
    ll cnt = 0;
    for (auto nxt: edges[cur]) {
        if (pre == nxt) continue;
        ll c = dfs(cur, nxt);
        if (ind[cur]) ans += c;
        else ans += cnt * c;
        cnt += c;
    }
    if (ind[cur]) return 1;
    else return cnt;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    ind.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        ind[i] = c == '1';
    }
    edges.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(0, 1);
    cout << ans * 2 << '\n';
}