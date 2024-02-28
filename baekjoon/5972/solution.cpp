#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
typedef pair<int, int> pi;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pi>> edges(n + 1);
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].emplace_back(c, b);
        edges[b].emplace_back(c, a);
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> dst(n + 1, inf);
    dst[1] = 0;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (dst[cur] < d) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (dst[nxt] > d + w) {
                dst[nxt] = d + w;
                pq.emplace(d + w, nxt);
            }
        }
    }

    cout << dst[n] << '\n';
}