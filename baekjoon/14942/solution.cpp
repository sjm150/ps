#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> edges;
vector<int> e, stk, dst, ans;

void dfs(int pre, int cur) {
    int d = dst.back();
    ans[cur] = stk[lower_bound(dst.begin(), dst.end(), d - e[cur]) - dst.begin()];
    for (auto [w, nxt]: edges[cur]) {
        if (nxt == pre) continue;
        stk.push_back(nxt);
        dst.push_back(d + w);
        dfs(cur, nxt);
        stk.pop_back();
        dst.pop_back();
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    e.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> e[i];
    edges.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].emplace_back(c, b);
        edges[b].emplace_back(c, a);
    }

    ans.resize(n + 1);
    stk.push_back(1);
    dst.push_back(0);
    dfs(0, 1);

    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}