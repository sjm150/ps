#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<vector<pi>> edges;
vector<int> clr;
int cut;

bool dfs(int cur, int c) {
    clr[cur] = c;
    for (auto &[nxt, cnd]: edges[cur]) {
        if (cnd < cut) continue;
        if (clr[nxt] < 0 && !dfs(nxt, 1 - c)) return false;
        else if (clr[cur] == clr[nxt]) return false;
    }
    return true;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vector<pi> prs(m);
    for (int i = 0; i < m; i++) cin >> prs[i].first >> prs[i].second;
    vector<int> cnd(m, k);
    for (int i = 0; i < k; i++) {
        int r; cin >> r;
        cnd[r - 1] = i;
    }

    edges.resize(n + 1);
    for (int i = 0; i < m; i++) {
        auto &[u, v] = prs[i];
        edges[u].emplace_back(v, cnd[i]);
        edges[v].emplace_back(u, cnd[i]);
    }
    clr.resize(n + 1);

    int l = 0, r = k + 1;
    while (l < r) {
        cut = (l + r) / 2;
        fill(clr.begin(), clr.end(), -1);
        if (dfs(1, 0)) r = cut;
        else l = cut + 1;
    }

    if (l <= k) {
        fill(clr.begin(), clr.end(), -1);
        cut = l;
        dfs(1, 0);

        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (clr[j] == 0) cnt++;
        }

        cout << l << '\n';
        cout << min(cnt, n - cnt) << ' ' << max(cnt, n - cnt) << '\n';
    } else {
        cout << -1 << '\n';
    }
}