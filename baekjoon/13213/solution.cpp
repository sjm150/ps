#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    typedef pair<int, int> pi;
    const ll inf = 1e18;
    int n, e;
    cin >> n >> e;
    vector<vector<pi>> edges(n);
    while (e--) {
        int a, b, v;
        cin >> a >> b >> v;
        edges[a].emplace_back(v, b);
        edges[b].emplace_back(v, a);
    }

    vector<vector<ll>> dst(2, vector<ll>(n, inf));
    queue<pi> q;
    dst[0][0] = dst[1][0] = 0;
    q.emplace(0, 0);
    q.emplace(1, 0);
    while (!q.empty()) {
        auto [b, cur] = q.front();
        q.pop();
        for (auto [w, nxt]: edges[cur]) {
            if (b == w && dst[1 - b][nxt] == inf) {
                dst[1 - b][nxt] = dst[b][cur] + 1;
                q.emplace(1 - b, nxt);
            }
        }
    }

    ll d = min(dst[0][n - 1], dst[1][n - 1]);
    cout << (d < inf ? d : -1) << '\n';
}