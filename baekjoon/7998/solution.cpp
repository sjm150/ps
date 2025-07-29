#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m, n;
    cin >> m >> n;
    vector<int> x(m - 1), y(n - 1);
    for (int &x: x) cin >> x;
    for (int &y: y) cin >> y;
    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end(), greater<int>());

    vector<vector<int>> cst(m, vector<int>(n));
    cst[0][0] = 0;
    for (int i = 1; i < n; i++) cst[0][i] = cst[0][i - 1] + y[i - 1];
    for (int i = 1; i < m; i++) {
        cst[i][0] = cst[i - 1][0] + x[i - 1];
        for (int j = 1; j < n; j++) cst[i][j] = min(cst[i - 1][j] + x[i - 1] * (j + 1), cst[i][j - 1] + (i + 1) * y[j - 1]);
    }
    cout << cst[m - 1][n - 1] << '\n';
}