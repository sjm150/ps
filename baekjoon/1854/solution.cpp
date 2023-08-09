#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

vector<pi> edges[1001];
priority_queue<int> dst[1001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].emplace_back(c, b);
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dst[1].push(0);
    pq.emplace(0, 1);
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (dst[cur].top() < d) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (dst[nxt].size() < k) {
                dst[nxt].push(d + w);
                pq.emplace(d + w, nxt);
            } else if (dst[nxt].top() > d + w) {
                dst[nxt].pop();
                dst[nxt].push(d + w);
                pq.emplace(d + w, nxt);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dst[i].size() == k) cout << dst[i].top() << '\n';
        else cout << -1 << '\n';
    }
}