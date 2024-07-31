#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, w, p; cin >> n >> w >> p;
    vector<vector<int>> dst(n, vector<int>(n, 1e9));
    while (w--) {
        int u, v, d; cin >> u >> v >> d;
        u--, v--;
        dst[u][v] = dst[v][u] = d;
    }
    for (int i = 0; i < n; i++) dst[i][i] = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dst[i][j] > dst[i][k] + dst[k][j]) dst[i][j] = dst[i][k] + dst[k][j];
            }
        }
    }
    while (p--) {
        int u, v; cin >> u >> v;
        cout << dst[u - 1][v - 1] << '\n';
    }
}