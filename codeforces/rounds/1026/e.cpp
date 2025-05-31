#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct Edge {
        int t, r, idx;
        bool used = false;
        Edge(int t, int r, int idx): t(t), r(r), idx(idx) {}
    } e_t;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> vp(n);
        for (auto &[v, p]: vp) cin >> v >> p;

        map<int, int> vv, pv;
        int sz = 0;
        for (auto [v, p]: vp) {
            if (vv.find(v) == vv.end()) vv[v] = sz++;
            if (pv.find(p) == pv.end()) pv[p] = sz++;
        }

        vector<vector<e_t>> edges(sz);
        auto adde = [&](int u, int v, int idx) {
            edges[u].emplace_back(v, edges[v].size(), idx);
            edges[v].emplace_back(u, edges[u].size() - 1, idx);
        };
        for (int i = 0; i < n; i++) {
            auto [v, p] = vp[i];
            adde(vv[v], pv[p], i + 1);
        }

        vector<int> ov;
        for (int i = 0; i < sz; i++) {
            if (edges[i].size() % 2) ov.push_back(i);
        }

        vector<bool> vst(sz, false);
        function<void(int)> dfs = [&](int cur) {
            vst[cur] = true;
            for (auto &e: edges[cur]) {
                if (!vst[e.t]) dfs(e.t);
            }
        };
        dfs(0);
        bool conn = find(vst.begin(), vst.end(), false) == vst.end();

        if (conn && (ov.size() == 2 || ov.empty())) {
            vector<int> path, eidx(sz, 0);
            function<void(int, int)> dfs = [&](int cur, int idx) {
                while (eidx[cur] < int(edges[cur].size())) {
                    auto &e = edges[cur][eidx[cur]];
                    eidx[cur]++;
                    if (e.used) continue;
                    e.used = true;
                    edges[e.t][e.r].used = true;
                    dfs(e.t, e.idx);
                }
                if (idx >= 0) path.push_back(idx);
            };

            if (ov.empty()) {
                dfs(0, -1);
            } else {
                adde(ov[0], ov[1], 0);
                dfs(ov[0], -1);
                rotate(path.begin(), find(path.begin(), path.end(), 0) + 1, path.end());
                path.pop_back();
            }
            
            cout << "YES\n";
            for (int a: path) cout << a << ' ';
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}