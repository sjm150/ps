#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

typedef struct Djset {
    vector<pi> p;
    Djset(int n) {
        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = {i, 0};
    }

    pi find(int u) {
        if (p[u].first == u) return p[u];
        auto [r, d] = find(p[u].first);
        return p[u] = {r, d + p[u].second};
    }

    void uni(int u, int v, int d) {
        int du, dv;
        tie(u, du) = find(u);
        tie(v, dv) = find(v);
        if (u != v) p[u] = {v, d - du + dv};
    }

    pi dst(int u, int v) {
        int du, dv;
        tie(u, du) = find(u);
        tie(v, dv) = find(v);
        if (u != v) return {0, 0};
        return {1, du - dv};
    }
} djs_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    while (true) {
        int n, m; cin >> n >> m;
        if (n == 0) break;
        djs_t djs(n + 1);
        while (m--) {
            char q; cin >> q;
            if (q == '!') {
                int a, b, w; cin >> a >> b >> w;
                djs.uni(a, b, w);
            } else {
                int a, b; cin >> a >> b;
                auto [v, d] = djs.dst(a, b);
                if (v) cout << d << '\n';
                else cout << "UNKNOWN\n";
            }
        }
    }
}