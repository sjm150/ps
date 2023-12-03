#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<int> w;
vector<vector<int>> edges;
vector<pi> cache;
vector<vector<pi>> cont[2];
vector<int> iset;

pi getsum(int pre, int cur) {
    if (cache[cur].first >= 0) return cache[cur];
    auto &[sel, nsel] = cache[cur];
    sel = w[cur], nsel = 0;

    for (int nxt: edges[cur]) {
        if (nxt == pre) continue;
        auto [_sel, _nsel] = getsum(cur, nxt);

        sel += _nsel;
        cont[1][cur].emplace_back(0, nxt);

        if (_sel > _nsel) {
            nsel += _sel;
            cont[0][cur].emplace_back(1, nxt);
        } else {
            nsel += _nsel;
            cont[0][cur].emplace_back(0, nxt);
        }
    }
    return cache[cur];
}

void calc_iset(int sel, int cur) {
    if (sel) iset.push_back(cur);
    for (auto [_sel, nxt]: cont[sel][cur]) calc_iset(_sel, nxt);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    w.resize(n + 1);
    edges.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    cache.resize(n + 1, {-1, -1});
    cont[0].resize(n + 1);
    cont[1].resize(n + 1);
    auto [sel, nsel] = getsum(0, 1);
    if (sel > nsel) calc_iset(1, 1);
    else calc_iset(0, 1);

    cout << max(sel, nsel) << '\n';
    sort(iset.begin(), iset.end());
    for (int v: iset) cout << v << ' ';
    cout << '\n';
}