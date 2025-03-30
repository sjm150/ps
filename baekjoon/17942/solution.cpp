#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    int n, m; cin >> n >> m;
    vector<int> k(n);
    for (int &k: k) cin >> k;
    int r; cin >> r;
    vector<vector<pi>> edges(n);
    while (r--) {
        int a, b, d; cin >> a >> b >> d;
        edges[a - 1].emplace_back(b - 1, d);
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (int i = 0; i < n; i++) pq.emplace(k[i], i);
    vector<bool> done(n, false);
    int cnt = 0, ans = 0;
    while (cnt < m) {
        auto [ki, i] = pq.top(); pq.pop();
        if (ki > k[i]) continue;
        done[i] = true;
        cnt++;
        ans = max(ans, k[i]);
        for (auto [nxt, d]: edges[i]) {
            if (done[nxt]) continue;
            k[nxt] -= d;
            pq.emplace(k[nxt], nxt);
        }
    }
    cout << ans << '\n';
}