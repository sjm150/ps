#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    while (m--) {
        int u, v; cin >> u >> v;
        edges[v].push_back(u);
    }
    int k; cin >> k;

    vector<int> scc(n + 1, -1), vst(n + 1, -1);
    stack<int> stk;
    int v = 0, s = 0;
    function<int(int)> tarjan = [&](int cur) {
        int rch = vst[cur] = v++;
        stk.push(cur);
        for (int nxt: edges[cur]) {
            if (vst[nxt] < 0) rch = min(rch, tarjan(nxt));
            else if (scc[nxt] < 0) rch = min(rch, vst[nxt]);
        }
        if (rch == vst[cur]) {
            while (!stk.empty() && vst[stk.top()] >= rch) {
                scc[stk.top()] = s;
                stk.pop();
            }
            s++;
        }
        return rch;
    };
    for (int i = 1; i <= n; i++) {
        if (vst[i] < 0) tarjan(i);
    }

    vector<set<int>> sedges(s);
    vector<int> ssz(s, 0), cnt(s, 0), rch(s, -1);
    for (int i = 1; i <= n; i++) {
        for (int nxt: edges[i]) {
            if (scc[nxt] != scc[i]) sedges[scc[nxt]].insert(scc[i]);
        }
        ssz[scc[i]]++;
    }
    function<void(int)> dfs = [&](int cur) {
        rch[cur] = 0;
        for (int nxt: sedges[cur]) {
            if (rch[nxt] < 0) dfs(nxt);
            if (rch[nxt]) rch[cur] = 1;
        }
        if (rch[cur]) {
            cnt[cur] = ssz[cur];
            for (int nxt: sedges[cur]) {
                if (rch[nxt] && cnt[cur] < cnt[nxt] + ssz[cur]) cnt[cur] = cnt[nxt] + ssz[cur];
            }
        }
    };
    rch[scc[k]] = 1;
    if (ssz[scc[k]] == 1) cnt[scc[k]] = 0;
    else cnt[scc[k]] = ssz[scc[k]];
    for (int i = 0; i < s; i++) {
        if (rch[i] < 0) dfs(i);
    }

    int mxi = 0;
    for (int i = 1; i <= n; i++) {
        if (!rch[scc[i]] || i == k) continue;
        if (!mxi || cnt[scc[i]] > cnt[scc[mxi]]) mxi = i;
    }
    if (mxi && cnt[scc[mxi]] > 1) cout << mxi << ' ' << cnt[scc[mxi]] - 1 << '\n';
    else cout << 0 << '\n';
}