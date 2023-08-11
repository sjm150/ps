#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
const int inf = 123456789;

int dst[500];
bool sp[500][500];
void set_sp(vector<vector<int>>& pre, int cur) {
    for (int p: pre[cur]) {
        if (!sp[p][cur]) {
            sp[p][cur] = true;
            set_sp(pre, p);
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    while (true) {
        int n, m; cin >> n >> m;
        if (n == 0) break;
        int s, e; cin >> s >> e;
        vector<vector<pi>> edges(n);
        vector<vector<int>> pre(n);
        fill(dst, dst + n, inf);
        for (int i = 0; i < n; i++) fill(sp[i], sp[i] + n, false);
        while (m--) {
            int u, v, p; cin >> u >> v >> p;
            edges[u].emplace_back(p, v);
        }

        priority_queue<pi, vector<pi>, greater<pi>> pq;
        dst[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, cur] = pq.top(); pq.pop();
            if (d != dst[cur]) continue;
            for (auto [w, nxt]: edges[cur]) {
                if (dst[nxt] > d + w) {
                    dst[nxt] = d + w;
                    pre[nxt] = vector<int>(1, cur);
                    pq.emplace(d + w, nxt);
                } else if (dst[nxt] == d + w) {
                    pre[nxt].push_back(cur);
                }
            }
        }
        set_sp(pre, e);

        fill(dst, dst + n, inf);
        dst[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, cur] = pq.top(); pq.pop();
            if (d != dst[cur]) continue;
            for (auto [w, nxt]: edges[cur]) {
                if (sp[cur][nxt]) continue;
                if (dst[nxt] > d + w) {
                    dst[nxt] = d + w;
                    pq.emplace(d + w, nxt);
                }
            }
        }
        if (dst[e] < inf) cout << dst[e] << '\n';
        else cout << -1 << '\n';
    }
}