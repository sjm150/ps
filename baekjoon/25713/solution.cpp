#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> t(n + 1, vector<int>(m + 1, 0)), l = t;
    while (k--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        t[a][b]++;
        l[a][b]++;
        t[a][d + 1]--;
        l[c + 1][b]--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) t[i][j] += t[i][j - 1];
    }
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) l[i][j] += l[i - 1][j];
    }
    vector<vector<int>> cnt(n, vector<int>(m));
    cnt[0][0] = t[0][0];
    for (int i = 1; i < n; i++) cnt[i][0] = cnt[i - 1][0] + t[i][0];
    for (int j = 1; j < m; j++) cnt[0][j] = cnt[0][j - 1] + l[0][j];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            cnt[i][j] = min(cnt[i - 1][j] + t[i][j], cnt[i][j - 1] + l[i][j]);
        }
    }
    cout << cnt[n - 1][m - 1] << '\n';
}