#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, m;
        cin >> n >> m;
        vector<vector<pi>> edges(m);
        while (n--) {
            int x, y, z;
            cin >> x >> y >> z;
            edges[x].emplace_back(z, y);
            edges[y].emplace_back(z, x);
        }

        vector<int> dst(m, 1e9), pre(m, -1);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        dst[0] = 0;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [d, cur] = pq.top();
            pq.pop();
            if (d > dst[cur]) continue;
            for (auto [w, nxt]: edges[cur]) {
                if (dst[nxt] > d + w) {
                    dst[nxt] = d + w;
                    pre[nxt] = cur;
                    pq.emplace(d + w, nxt);
                }
            }
        }

        function<void(int)> prnt = [&](int cur) {
            if (pre[cur] >= 0) prnt(pre[cur]);
            cout << cur << ' ';
        };
        cout << "Case #" << tc << ": ";
        if (pre[m - 1] < 0) {
            cout << -1 << '\n';
        } else {
            prnt(m - 1);
            cout << '\n';
        }
    }
}