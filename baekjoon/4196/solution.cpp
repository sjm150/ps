#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> vst; int vidx = 1;
vector<int> scc;
vector<set<int>> sedges;

int tarjan(int cur, stack<int>& stk) {
    int minv = vst[cur] = vidx++;
    stk.push(cur);
    for (int nxt: edges[cur]) {
        if (vst[nxt] < 0) minv = min(minv, tarjan(nxt, stk));
        else if (scc[nxt] < 0) minv = min(minv, vst[nxt]);
    }
    if (minv == vst[cur]) {
        int sidx = sedges.size();
        sedges.push_back(set<int>());
        while (!stk.empty() && vst[stk.top()] >= vst[cur]) {
            scc[stk.top()] = sidx;
            for (int nxt: edges[stk.top()]) {
                if (scc[nxt] >= 0) sedges[sidx].insert(scc[nxt]);
            }
            stk.pop();
        }
    }
    return minv;
}

void sdfs(int cur, vector<bool>& svst) {
    svst[cur] = true;
    for (int nxt: sedges[cur]) {
        if (!svst[nxt]) sdfs(nxt, svst);
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        edges = vector<vector<int>>(n + 1);
        vst = vector<int>(n + 1, -1);
        scc = vector<int>(n + 1, -1);
        sedges = vector<set<int>>();
        while (m--) {
            int x, y; cin >> x >> y;
            edges[x].push_back(y);
        }
        stack<int> stk;
        for (int i = 1; i <= n; i++) {
            if (vst[i] < 0) tarjan(i, stk);
        }
        vector<bool> svst(sedges.size(), false);
        int cnt = 0;
        for (int i = sedges.size() - 1; i >= 0; i--) {
            if (!svst[i]) {
                sdfs(i, svst);
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}