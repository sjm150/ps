#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> vst, scc, sdeg;
int vidx;

int tarjan(int cur, stack<int>& stk) {
    int rch = vst[cur] = vidx++;
    stk.push(cur);
    for (int nxt: edges[cur]) {
        if (vst[nxt] < 0) rch = min(rch, tarjan(nxt, stk));
        else if (scc[nxt] < 0) rch = min(rch, vst[nxt]);
    }
    if (rch == vst[cur]) {
        int sidx = sdeg.size();
        sdeg.push_back(0);
        while (!stk.empty() && vst[stk.top()] >= vst[cur]) {
            int u = stk.top(); stk.pop();
            scc[u] = sidx;
            for (int nxt: edges[u]) {
                if (scc[nxt] < 0 || scc[nxt] == sidx) continue;
                sdeg[scc[nxt]]++;
            }
        }
    }
    return rch;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        edges = vector<vector<int>>(n);
        while (m--) {
            int a, b; cin >> a >> b;
            edges[a].push_back(b);
        }

        vst = scc = vector<int>(n, -1);
        sdeg = vector<int>();
        vidx = 0;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (vst[i] < 0) tarjan(i, stk);
        }

        bool poss = true;
        for (int i = 0; i < sdeg.size() - 1; i++) {
            if (sdeg[i] == 0) {
                poss = false;
                break;
            }
        }

        if (poss) {
            for (int i = 0; i < n; i++) {
                if (scc[i] == sdeg.size() - 1) cout << i << '\n';
            }
            cout << '\n';
        } else {
            cout << "Confused\n\n";
        }
    }
}