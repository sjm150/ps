#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
const int inf = 1e9;

vector<pi> edges[200001];
int dst[200001], pre[200001];
bool sp[200001];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].emplace_back(c, b);
        edges[b].emplace_back(c, a);
    }
    int s, e; cin >> s >> e;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    fill(dst, dst + n + 1, inf);
    dst[e] = 0;
    pq.emplace(dst[e], e);
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (d != dst[cur]) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (dst[nxt] > d + w) {
                dst[nxt] = d + w;
                pre[nxt] = cur;
                pq.emplace(d + w, nxt);
            } else if (dst[nxt] == d + w) {
                pre[nxt] = min(pre[nxt], cur);
            }
        }
    }

    int cur = s;
    while (cur > 0) {
        sp[cur] = true;
        cur = pre[cur];
    }
    for (int i = 1; i <= n; i++) {
        if (!sp[i]) dst[i] = inf;
    }
    dst[e] = inf;

    pq.emplace(dst[s], s);
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (d != dst[cur]) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (dst[nxt] > d + w) {
                dst[nxt] = d + w;
                pq.emplace(d + w, nxt);
            }
        }
    }
    cout << dst[e] << '\n';
}