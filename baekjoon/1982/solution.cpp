#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int inf = 1e9;
    int m, f, r, c; cin >> m >> f >> r >> c;
    vector<vector<vector<int>>> cst(m + 1, vector<vector<int>>(f + 1, vector<int>(2, inf)));
    cst[0][0][0] = 0;
    while (r--) {
        int a, b; cin >> a >> b;
        for (int i = m; i >= 0; i--) {
            for (int j = f; j >= 0; j--) {
                cst[i][j][0] = min(cst[i][j][0], min(cst[max(0, i - a)][j][0], cst[i][max(0, j - a)][0]) + b);
                cst[i][j][1] = min(cst[i][j][1], min(cst[max(0, i - a)][j][1], cst[i][max(0, j - a)][1]) + b);
                if (a > 1 && i && j) cst[i][j][1] = min(cst[i][j][1], cst[i - 1][j - 1][0] + b);
            }
        }
    }
    int ans = cst[m][f][0];
    if (c) ans = min(ans, cst[m][f][1]);
    if (ans < inf) cout << ans << '\n';
    else cout << "Impossible\n";
}