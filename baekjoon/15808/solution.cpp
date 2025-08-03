#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    const int inf = 1e9;
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n));
    for (auto &d: d) {
        for (int &d: d) {
            cin >> d;
            if (d == 0) d = inf;
        }
    }
    int p, q;
    cin >> p >> q;
    vector<pi> plw(p), qlw(q);
    for (auto &[l, w]: plw) {
        cin >> l >> w;
        l--;
    }
    for (auto &[l, w]: qlw) {
        cin >> l >> w;
        l--;
    }

    vector<int> dst(n, inf);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (auto [l, w]: plw) {
        dst[l] = -w;
        pq.emplace(-w, l);
    }
    while (!pq.empty()) {
        auto [w, cur] = pq.top();
        pq.pop();
        if (w > dst[cur]) continue;
        for (int i = 0; i < n; i++) {
            if (dst[i] > w + d[cur][i]) {
                dst[i] = w + d[cur][i];
                pq.emplace(dst[i], i);
            }
        }
    }

    int ans = -inf;
    for (auto [l, w]: qlw) ans = max(ans, w - dst[l]);
    cout << ans << '\n';
}