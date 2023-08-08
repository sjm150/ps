#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int inf = 123456789;

vector<pi> edges[801];
int dst[801];
void dijk(int n, int v) {
    fill(dst, dst + n + 1, inf);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dst[v] = 0;
    pq.emplace(0, v);
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (d != dst[cur]) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (dst[nxt] > d + w) {
                dst[nxt] = d + w;
                pq.emplace(dst[nxt], nxt);
            }
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, e; cin >> n >> e;
    while (e--) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].emplace_back(c, b);
        edges[b].emplace_back(c, a);
    }
    int v1, v2; cin >> v1 >> v2;
    dijk(n, v1);
    int s1 = dst[1], bet = dst[v2], e1 = dst[n];
    dijk(n, v2);
    int s2 = dst[1], e2 = dst[n];
    int ans = min(s1 + e2, s2 + e1) + bet;
    if (ans < inf) cout << ans << '\n';
    else cout << -1 << '\n';
}