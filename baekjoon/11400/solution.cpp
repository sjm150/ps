#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> vst; int vidx;
vector<pair<int, int>> ans;

int dfs(int pre, int cur) {
    int rch = vst[cur] = vidx++;
    for (int nxt: edges[cur]) {
        if (vst[nxt] < 0) {
            int nrch = dfs(cur, nxt);
            rch = min(rch, nrch);
            if (nrch > vst[cur]) {
                ans.emplace_back(min(cur, nxt), max(cur, nxt));
            }
        } else if (nxt != pre) {
            rch = min(rch, vst[nxt]);
        }
    }
    return rch;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int v, e; cin >> v >> e;
    edges.resize(v + 1);
    while (e--) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vst.resize(v + 1, -1);
    dfs(0, 1);

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto &[v, u]: ans) cout << v << ' ' << u << '\n';
}