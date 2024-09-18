#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<vb> vvb;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k, m; cin >> n >> k >> m;
    vvb z(n, vb(n, false));
    vvb p = z;
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        p[i][u - 1] = p[i][v - 1] = true;
    }
    function<vvb(const vvb&, const vvb&)> mul = [&](const vvb &a, const vvb &b) {
        vvb c = z;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][k] && b[k][j]) c[i][j] = true;
                }
            }
        }
        return c;
    };
    function<vvb(vvb&, int)> pow = [&](vvb &p, int x) {
        if (x == 1) return p;
        vvb t = pow(p, x / 2);
        if (x % 2) return mul(t, mul(t, p));
        else return mul(t, t);
    };
    vvb r = pow(p, k);
    while (m--) {
        int a, b; cin >> a >> b;
        cout << (r[a - 1][b - 1] ? "death\n" : "life\n");
    }
}