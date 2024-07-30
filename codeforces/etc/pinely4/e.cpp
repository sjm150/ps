#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n;
        if (n == -1) break;
        cin >> m;
        vector<vector<int>> edges(n + 1);
        while (m--) {
            int u, v; cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        vector<int> vst(n + 1, -1);
        function<void(int, int)> dfs = [&](int cur, int v) {
            vst[cur] = v;
            for (int nxt: edges[cur]) {
                if (vst[nxt] < 0) dfs(nxt, 1 - v);
            }
        };
        dfs(1, 0);
        bool poss = true;
        for (int i = 1; i <= n; i++) {
            for (int j: edges[i]) {
                if (vst[i] == vst[j]) {
                    poss = false;
                    break;
                }
            }
        }
        if (poss) {
            cout << "Bob" << endl;
            if (n == 1) {
                int u, v; cin >> u >> v;
                cout << 1 << ' ' << u << endl;
                continue;
            }
            vector<vector<int>> vtx(2);
            for (int i = 1; i <= n; i++) vtx[vst[i]].push_back(i);
            int c0, c1;
            int u, v; cin >> u >> v;
            c0 = u;
            cout << vtx[0].back() << ' ' << c0 << endl;
            vtx[0].pop_back();
            cin >> u >> v;
            if (u != c0) c1 = u;
            else c1 = v;
            cout << vtx[1].back() << ' ' << c1 << endl;
            vtx[1].pop_back();
            for (int i = 0; i < n - 2; i++) {
                cin >> u >> v;
                if (!vtx[0].empty() && (u == c0 || v == c0)) {
                    cout << vtx[0].back() << ' ' << c0 << endl;
                    vtx[0].pop_back();
                } else if (!vtx[1].empty() && (u == c1 || v == c1)) {
                    cout << vtx[1].back() << ' ' << c1 << endl;
                    vtx[1].pop_back();
                } else {
                    if (!vtx[0].empty()) {
                        cout << vtx[0].back() << ' ' << 6 - c0 - c1 << endl;
                        vtx[0].pop_back();
                    } else {
                        cout << vtx[1].back() << ' ' << 6 - c0 - c1 << endl;
                        vtx[1].pop_back();
                    }
                }
            }
        } else {
            cout << "Alice" << endl;
            for (int i = 0; i < n; i++) {
                cout << "1 2" << endl;
                int idx, c; cin >> idx >> c;
            }
        }
    }
}