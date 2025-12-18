#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    const int inf = 2e9 + 5;

    int c, p, pb, pa1, pa2;
    cin >> c >> p >> pb >> pa1 >> pa2;
    pb--, pa1--, pa2--;
    vector<vector<pi>> edges(p);
    while (c--) {
        int a, b, d;
        cin >> a >> b >> d;
        a--, b--;
        edges[a].emplace_back(d, b);
        edges[b].emplace_back(d, a);
    }

    auto get = [&](int s, int t1, int t2) {
        vector<int> dst(p, inf);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        dst[s] = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [d, cur] = pq.top();
            pq.pop();
            if (dst[cur] < d) continue;
            for (auto [w, nxt]: edges[cur]) {
                if (dst[nxt] > dst[cur] + w) {
                    dst[nxt] = dst[cur] + w;
                    pq.emplace(dst[nxt], nxt);
                }
            }
        }
        return dst[t1] + dst[t2];
    };

    cout << min(get(pa1, pb, pa2), get(pa2, pb, pa1)) << '\n';
}