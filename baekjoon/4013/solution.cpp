#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> w;
vector<bool> tar;

vector<int> vst, scc;
int vidx;
vector<set<int>> sedges;
vector<int> sw;
vector<bool> star;

int tarjan(int cur, stack<int>& stk) {
    int rch = vst[cur] = vidx++;
    stk.push(cur);
    for (int nxt: edges[cur]) {
        if (vst[nxt] < 0) rch = min(rch, tarjan(nxt, stk));
        else if (scc[nxt] < 0) rch = min(rch, vst[nxt]);
    }
    if (rch == vst[cur]) {
        int sidx = sedges.size();
        sedges.emplace_back();
        sw.emplace_back();
        star.emplace_back();
        while (!stk.empty() && vst[stk.top()] >= vst[cur]) {
            int u = stk.top(); stk.pop();
            scc[u] = sidx;
            for (int nxt: edges[u]) {
                if (scc[nxt] < 0 || scc[nxt] == sidx) continue;
                sedges[sidx].insert(scc[nxt]);
            }
            sw[sidx] += w[u];
            if (tar[u]) star[sidx] = true;
        }
    }
    return rch;
}

vector<int> cache;

int dfs(int cur) {
    if (cache[cur] >= 0) return cache[cur];
    int &sum = cache[cur];
    sum = 0;
    for (int nxt: sedges[cur]) {
        int d = dfs(nxt);
        if (!star[nxt]) continue;
        star[cur] = true;
        sum = max(sum, d);
    }
    if (star[cur]) sum += sw[cur];
    return sum;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    edges.resize(n + 1);
    w.resize(n + 1);
    while (m--) {
        int s, e; cin >> s >> e;
        edges[s].push_back(e);
    }
    for (int i = 1; i <= n; i++) cin >> w[i];
    int s, p; cin >> s >> p;
    tar.resize(n + 1, false);
    while (p--) {
        int u; cin >> u;
        tar[u] = true;
    }

    vst = scc = vector<int>(n + 1, -1);
    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        if (vst[i] < 0) tarjan(i, stk);
    }

    cache.resize(sedges.size(), -1);
    cout << dfs(scc[s]) << '\n';
}