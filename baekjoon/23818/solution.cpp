#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> edges(n);
    while (m--) {
        int t, a, b;
        cin >> t >> a >> b;
        a--, b--;
        edges[a].emplace_back(t, b);
        edges[b].emplace_back(t, a);
    }

    vector<int> grp(n);
    vector<bool> vst(n, false), odd(n), ge;
    function<void(int, int, bool)> dfs = [&](int cur, int g, bool o) {
        vst[cur] = true;
        grp[cur] = g;
        odd[cur] = o;
        for (auto [t, nxt]: edges[cur]) {
            if (vst[nxt]) {
                if (int(odd[cur] != odd[nxt]) != t) ge[g] = true;
            } else {
                dfs(nxt, g, t ? !o : o);
            }
        };
    };
    for (int i = 0; i < n; i++) {
        if (vst[i]) continue;
        ge.push_back(false);
        dfs(i, ge.size() - 1, false);
    }

    while (k--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (grp[a] != grp[b]) cout << "Unknown\n";
        else if (ge[grp[a]]) cout << "Error\n";
        else cout << (odd[a] == odd[b] ? "Friend\n" : "Enemy\n");
    }
}