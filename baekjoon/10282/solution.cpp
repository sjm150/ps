#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, d, c; cin >> n >> d >> c;
        vector<vector<pi>> edges(n + 1);
        while (d--) {
            int a, b, s; cin >> a >> b >> s;
            edges[b].emplace_back(s, a);
        }
        vector<int> dst(n + 1, inf);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        dst[c] = 0;
        pq.emplace(c, 0);
        while (!pq.empty()) {
            auto [cur, d] = pq.top(); pq.pop();
            if (dst[cur] != d) continue;
            for (auto &[s, nxt]: edges[cur]) {
                if (dst[nxt] > d + s) {
                    dst[nxt] = d + s;
                    pq.emplace(nxt, d + s);
                }
            }
        }
        int cnt = 0, mxt = 0;
        for (int i = 1; i <= n; i++) {
            if (dst[i] < inf) {
                cnt++;
                mxt = max(mxt, dst[i]);
            }
        }
        cout << cnt << ' ' << mxt << '\n';
    }
}