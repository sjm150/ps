#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int inf = 1e9;

vector<vector<pi>> edges;
int dst[501];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int tc; cin >> tc;
    while (tc--) {
        int n, m, w; cin >> n >> m >> w;
        edges = vector<vector<pi>>(n + 1);
        fill(dst, dst + n + 1, inf);
        while (m--) {
            int s, e, t; cin >> s >> e >> t;
            edges[s].emplace_back(t, e);
            edges[e].emplace_back(t, s);
        }
        while (w--) {
            int s, e, t; cin >> s >> e >> t;
            edges[s].emplace_back(-t, e);
        }
        bool updated = false;
        dst[1] = 0;
        for (int i = 0; i < n; i++) {
            updated = false;
            for (int cur = 1; cur <= n; cur++) {
                for (auto& [t, nxt]: edges[cur]) {
                    if (dst[nxt] > dst[cur] + t) {
                        dst[nxt] = dst[cur] + t;
                        updated = true;
                    }
                }
            }
        }
        if (updated) cout << "YES\n";
        else cout << "NO\n";
    }
}