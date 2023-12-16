#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> vst, low, ans;
int vidx, cnt;

void dfs(int pre, int cur) {
    low[cur] = vst[cur] = vidx++;
    bool cut = false;
    int ccnt = 0;
    for (int nxt: edges[cur]) {
        if (vst[nxt] < 0) {
            dfs(cur, nxt);
            low[cur] = min(low[cur], low[nxt]);
            ccnt++;
            if (low[nxt] >= vst[cur]) cut = true;
        } else {
            low[cur] = min(low[cur], vst[nxt]);
        }
    }
    if ((pre && cut) || (pre == 0 && ccnt > 1)) ans.push_back(cur);
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
    low.resize(v + 1, -1);
    for (int i = 1; i <= v; i++) {
        if (vst[i] < 0) dfs(0, i);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int a: ans) cout << a << ' ';
    cout << '\n';
}