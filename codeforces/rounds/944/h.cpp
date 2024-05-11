#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> g(3, vector<int>(n));
        for (auto &g: g) {
            for (auto &g: g) cin >> g;
        }

        vector<vector<int>> edges(2 * n);
        for (int i = 0; i < n; i++) {
            vector<int> v(3), nv(3);
            for (int j = 0; j < 3; j++) {
                v[j] = (g[j][i] > 0 ? g[j][i] - 1 : 2 * n + g[j][i]);
                nv[j] = 2 * n - 1 - v[j];
            }
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;
                    edges[nv[j]].push_back(v[k]);
                }
            }
        }

        vector<int> vst(2 * n, -1), scc(2 * n, -1);
        int vidx = 0, sidx = 0;
        stack<int> stk;
        function<int(int)> tarjan = [&](int cur) {
            int rch = vst[cur] = vidx++;
            stk.push(cur);
            for (int nxt: edges[cur]) {
                if (vst[nxt] < 0) rch = min(rch, tarjan(nxt));
                else if (scc[nxt] < 0) rch = min(rch, vst[nxt]);
            }
            if (rch == vst[cur]) {
                while (!stk.empty() && vst[stk.top()] >= vst[cur]) {
                    scc[stk.top()] = sidx;
                    stk.pop();
                }
                sidx++;
            }
            return rch;
        };

        for (int i = 0; i < 2 * n; i++) {
            if (vst[i] < 0) tarjan(i);
        }

        bool poss = true;
        for (int i = 0; i < n; i++) {
            if (scc[i] == scc[2 * n - 1 - i]) {
                poss = false;
                break;
            }
        }

        cout << (poss ? "YES\n" : "NO\n");
    }
}