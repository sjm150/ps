#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n + 1);
    vector<int> indeg(n + 1, 0);
    while (m--) {
        int s, e, w; cin >> s >> e >> w;
        edges[s].emplace_back(w, e);
        indeg[e]++;
    }

    int s, e; cin >> s >> e;
    vector<ll> dst(n + 1, 0);
    vector<vector<int>> pre(n + 1);
    queue<int> q;

    q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto &[w, nxt]: edges[cur]) {
            if (dst[nxt] < dst[cur] + w) {
                dst[nxt] = dst[cur] + w;
                pre[nxt].clear();
                pre[nxt].push_back(cur);
            } else if (dst[nxt] == dst[cur] + w) {
                pre[nxt].push_back(cur);
            }
            indeg[nxt]--;
            if (indeg[nxt] == 0) q.push(nxt);
        }
    }

    vector<bool> vst(n + 1, false);
    int cnt = 0;
    vst[e] = true;
    q.push(e);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int p: pre[cur]) {
            cnt++;
            if (vst[p]) continue;
            vst[p] = true;
            q.push(p);
        }
    }

    cout << dst[e] << '\n' << cnt << '\n';
}