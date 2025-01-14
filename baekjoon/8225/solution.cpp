#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct Djset {
        vector<int> p;
        Djset(int n) {
            p.resize(n);
            iota(p.begin(), p.end(), 0);
        }
        int find(int u) {
            if (p[u] == u) return u;
            return p[u] = find(p[u]);
        }
        void uni(int u, int v) {
            u = find(u), v = find(v);
            p[u] = v;
        }
    } djs_t;
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> edges(m);
    for (auto &[u, v]: edges) {
        cin >> u >> v;
        u--, v--;
        if (u > v) swap(u, v);
    }
    sort(edges.begin(), edges.end(), greater<pair<int, int>>());
    djs_t djs(n);
    vector<pair<int, int>> ans;
    for (auto [u, v]: edges) {
        if (u < k) {
            int ur = djs.find(u), vr = djs.find(v);
            if (ur == vr) ans.emplace_back(u, v);
            else djs.uni(ur, vr);
        } else {
            djs.uni(u, v);
        }
    }
    cout << ans.size() << '\n';
    for (auto [u, v]: ans) cout << u + 1 << ' ' << v + 1 << '\n';
}