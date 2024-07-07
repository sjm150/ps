#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, b, c; cin >> a >> b >> c;
    string x, y; cin >> x >> y;
    int n = x.size(), m = y.size();
    vector<vector<int>> scr(n + 1, vector<int>(m + 1));
    scr[0][0] = 0;
    for (int i = 1; i <= n; i++) scr[i][0] = scr[i - 1][0] + b;
    for (int j = 1; j <= m; j++) scr[0][j] = scr[0][j - 1] + b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scr[i][j] = max(max(scr[i - 1][j], scr[i][j - 1]) + b, scr[i - 1][j - 1] + (x[i - 1] == y[j - 1] ? a : c));
        }
    }
    cout << scr[n][m] << '\n';
}