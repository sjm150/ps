#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int inf = 123456789;

vector<int> dijk(int s, vector<vector<pi>>& edges) {
    vector<int> dst(edges.size(), inf);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dst[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (dst[cur] != d) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (dst[nxt] > d + w) {
                dst[nxt] = d + w;
                pq.emplace(dst[nxt], nxt);
            }
        }
    }
    return dst;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        int n, m, t; cin >> n >> m >> t;
        int s, g, h; cin >> s >> g >> h;
        vector<vector<pi>> edges(n + 1);
        vector<int> cands(t);
        int ghd;
        while (m--) {
            int a, b, d; cin >> a >> b >> d;
            if ((g == a && h == b) || (g == b && h == a)) ghd = d;
            edges[a].emplace_back(d, b);
            edges[b].emplace_back(d, a);
        }
        for (int i = 0; i < t; i++) cin >> cands[i];
        sort(cands.begin(), cands.end());

        auto sdst = dijk(s, edges);
        auto gdst = dijk(g, edges);
        auto hdst = dijk(h, edges);
        for (int x: cands) {
            if (ghd + min(gdst[s] + hdst[x], gdst[x] + hdst[s]) == sdst[x]) cout << x << ' ';
        }
        cout << '\n';
    }
}