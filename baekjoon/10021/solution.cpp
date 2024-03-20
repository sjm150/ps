#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef pair<int, pi> ti;

typedef struct Djset {
    vector<int> p;
    Djset(int n): p(n) { iota(p.begin(), p.end(), 0); }
    int find(int u) {
        if (p[u] == u) return u;
        return p[u] = find(p[u]);
    }
    bool uni(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        p[u] = v;
        return true;
    }
} djs_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, c; cin >> n >> c;
    vector<pi> fld(n);
    for (auto &[x, y]: fld) cin >> x >> y;

    vector<ti> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = (fld[i].first - fld[j].first) * (fld[i].first - fld[j].first)
                + (fld[i].second - fld[j].second) * (fld[i].second - fld[j].second);
            if (d >= c) edges.emplace_back(d, pi(i, j));
        }
    }
    sort(edges.begin(), edges.end());

    djs_t djs(n);
    long long ans = 0;
    int cnt = n - 1;
    for (auto &[d, xy]: edges) {
        auto &[u, v] = xy;
        if (djs.uni(u, v)) {
            ans += d;
            cnt--;
        }
    }

    if (cnt == 0) cout << ans << '\n';
    else cout << -1 << '\n';
}