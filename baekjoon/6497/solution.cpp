#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;

typedef struct DjSet {
    vector<int> p;
    DjSet(int m) {
        p = vector<int>(m);
        iota(p.begin(), p.end(), 0);
    }
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
    while (true) {
        int m, n; cin >> m >> n;
        if (m == 0) break;
        vector<ti> edges(n);
        for (int i = 0; i < n; i++) {
            int x, y, z; cin >> x >> y >> z;
            edges.emplace_back(z, x, y);
        }
        sort(edges.begin(), edges.end());

        djs_t djs(m);
        int tot = 0, sum = 0;
        for (auto [d, u, v]: edges) {
            tot += d;
            if (djs.uni(u, v)) sum += d;
        }
        cout << tot - sum << '\n';
    }
}