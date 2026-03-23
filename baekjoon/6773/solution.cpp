#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef tuple<int, int, int> ti;
    const int inf = 1e9;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n);
    while (m--) {
        int a, b, l;
        cin >> a >> b >> l;
        edges[a - 1].emplace_back(l, b - 1);
    }

    vector<vector<int>> dst(n, vector<int>(2, inf));
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    dst[0][0] = 0;
    pq.emplace(0, 0, 0);
    while (!pq.empty()) {
        auto [d, i, cur] = pq.top();
        pq.pop();
        if (dst[cur][i] < d) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (dst[nxt][0] > d + w) {
                dst[nxt][1] = dst[nxt][0];
                pq.emplace(dst[nxt][1], 1, nxt);
                dst[nxt][0] = d + w;
                pq.emplace(d + w, 0, nxt);
            } else if (dst[nxt][0] < d + w && d + w < dst[nxt][1]) {
                dst[nxt][1] = d + w;
                pq.emplace(d + w, 1, nxt);
            }
        }
    }

    cout << (dst[n - 1][1] < inf ? dst[n - 1][1] : -1) << '\n';
}