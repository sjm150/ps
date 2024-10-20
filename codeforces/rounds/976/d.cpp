#include <bits/stdc++.h>
using namespace std;

typedef struct Djset {
    vector<int> p;
    Djset(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void uni(int u, int v) {
        u = find(u), v = find(v);
        p[u] = v;
    }
} djs_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<djs_t> con(11, n + 1);
        while (m--) {
            int a, d, k; cin >> a >> d >> k;
            for (int i = a; i < a + d * k; i += d) {
                int r = con[d].find(i);
                if (r == i) con[d].uni(i, i + d);
                else i = r - d;
            }
        }
        djs_t djs(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int d = 1; d <= 10; d++) {
                int r = con[d].find(i);
                if (r != i) djs.uni(i, r);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (djs.find(i) == i) ans++;
        }
        cout << ans << '\n';
    }
}