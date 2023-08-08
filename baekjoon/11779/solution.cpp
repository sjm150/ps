#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int inf = 123456789;

vector<pi> edges[1001];
int dst[1001];
int pre[1001];
void print(int cur, int cnt) {
    if (pre[cur] == -1) cout << cnt << '\n';
    else print(pre[cur], cnt + 1);
    cout << cur << ' ';
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        edges[u].emplace_back(w, v);
    }
    int s, e; cin >> s >> e;
    fill(dst, dst + n + 1, inf);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dst[s] = 0; pre[s] = -1;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (d != dst[cur]) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (dst[nxt] > d + w) {
                dst[nxt] = d + w; pre[nxt] = cur;
                pq.emplace(dst[nxt], nxt);
            }
        }
    }
    cout << dst[e] << '\n';
    print(e, 1);
    cout << '\n';
}