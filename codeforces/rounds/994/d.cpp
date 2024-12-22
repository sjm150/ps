#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll inf = 1e18;
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<vector<int>> a(n, vector<int>(m));
        for (auto &a: a) {
            for (int &a: a) cin >> a;
        }
        vector<vector<vector<ll>>> cst(n, vector<vector<ll>>(m, vector<ll>(m)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i) {
                    ll u = inf;
                    for (int r = 0; r < m; r++) u = min(u, cst[i - 1][j][r]);
                    for (int r = 0; r < m; r++) {
                        cst[i][j][r] = u + ll(k) * r + a[i][(j + r) % m];
                        if (j && cst[i][j - 1][r] + a[i][(j + r) % m] < cst[i][j][r]) cst[i][j][r] = cst[i][j - 1][r] + a[i][(j + r) % m];
                    }
                } else {
                    if (j) {
                        for (int r = 0; r < m; r++) cst[0][j][r] = cst[0][j - 1][r] + a[0][(j + r) % m];
                    } else {
                        for (int r = 0; r < m; r++) cst[0][0][r] = ll(k) * r + a[0][r];
                    }
                }
            }
        }
        cout << *min_element(cst[n - 1][m - 1].begin(), cst[n - 1][m - 1].end()) << '\n';
    }
}