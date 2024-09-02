#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;

const ll inf = 1e18;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pli>> edges(n);
    vector<int> idx(n * n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        edges[u].emplace_back(w, v);
        idx[u * n + v] = i;
    }

    vector<int> cnt(m, 0);
    for (int s = 0; s < n; s++) {
        vector<ll> dst(n, inf);
        vector<int> pre(n, -1);
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        dst[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, cur] = pq.top(); pq.pop();
            if (d != dst[cur]) continue;
            for (auto &[w, nxt]: edges[cur]) {
                if (dst[nxt] > d + w) {
                    dst[nxt] = d + w;
                    pre[nxt] = cur;
                    pq.emplace(d + w, nxt);
                }
            }
        }
        vector<vector<int>> chld(n);
        for (int i = 0; i < n; i++) {
            if (pre[i] >= 0) chld[pre[i]].push_back(i);
        }
        function<int(int)> dfs = [&](int cur) {
            int sum = 1;
            for (int nxt: chld[cur]) {
                int c = dfs(nxt);
                cnt[idx[cur * n + nxt]] += c;
                sum += c;
            }
            return sum;
        };
        dfs(s);
    }

    int mx = *max_element(cnt.begin(), cnt.end());
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        if (cnt[i] == mx) ans.push_back(i + 1);
    }
    cout << ans.size() << '\n';
    for (int a: ans) cout << a << ' ';
    cout << '\n';
}