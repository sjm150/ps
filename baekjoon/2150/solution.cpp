#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> vst; int vidx = 1;
vector<int> scc;
vector<vector<int>> sset;

int tarjan(int cur, stack<int>& stk) {
    int minv = vst[cur] = vidx++;
    stk.push(cur);
    for (int nxt: edges[cur]) {
        if (vst[nxt] < 0) {
            minv = min(minv, tarjan(nxt, stk));
        } else if (scc[nxt] < 0) {
            minv = min(minv, vst[nxt]);
        }
    }
    if (minv == vst[cur]) {
        vector<int> curc;
        while (!stk.empty() && vst[stk.top()] >= vst[cur]) {
            scc[stk.top()] = sset.size();
            curc.push_back(stk.top());
            stk.pop();
        }
        sort(curc.begin(), curc.end());
        sset.push_back(curc);
    }
    return minv;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int v, e; cin >> v >> e;
    edges.resize(v + 1);
    vst.resize(v + 1, -1);
    scc.resize(v + 1, -1);
    while (e--) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
    }
    stack<int> stk;
    for (int i = 1; i <= v; i++) {
        if (vst[i] < 0) tarjan(i, stk);
    }
    cout << sset.size() << '\n';
    vector<bool> printed(sset.size(), false);
    for (int i = 1; i <= v; i++) {
        if (printed[scc[i]]) continue;
        printed[scc[i]] = true;
        for (int mem: sset[scc[i]]) cout << mem << ' ';
        cout << "-1\n";
    }
}