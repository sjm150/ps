#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, h, m;
    cin >> n >> h >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<vector<int>> mxh(n + 1, vector<int>(m + 1, -1));
    mxh[0][m] = h;
    int i = 1;
    for (; i <= n; i++) {
        for (int j = 0; j <= m; j++) mxh[i][j] = max(mxh[i][j], max(mxh[i - 1][j] - a[i - 1], j + b[i - 1] <= m ? mxh[i - 1][j + b[i - 1]] : -1));
        if (*max_element(mxh[i].begin(), mxh[i].end()) < 0) break;
    }
    cout << i - 1 << '\n';
}