#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<int> w;
vector<vector<int>> edges;
vector<pi> cnts;

void calc_cnt(int pre, int cur) {
    auto &[sel, nsel] = cnts[cur];
    sel += w[cur];
    for (int nxt: edges[cur]) {
        if (nxt == pre) continue;
        calc_cnt(cur, nxt);
        sel += cnts[nxt].second;
        nsel += max(cnts[nxt].first, cnts[nxt].second);
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    w.resize(n + 1);
    edges.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    cnts.resize(n + 1, {0, 0});
    calc_cnt(0, 1);
    cout << max(cnts[1].first, cnts[1].second) << '\n';
}