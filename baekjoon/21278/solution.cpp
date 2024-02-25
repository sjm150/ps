#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> dst(n, vector<int>(n, inf));
    while (m--) {
        int a, b; cin >> a >> b;
        --a, --b;
        dst[a][b] = 1;
        dst[b][a] = 1;
    }
    for (int i = 0; i < n; i++) dst[i][i] = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dst[i][j] > dst[i][k] + dst[k][j]) dst[i][j] = dst[i][k] + dst[k][j];
            }
        }
    }

    int a = 0, b = 1, d = inf;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) sum += 2 * min(dst[i][k], dst[j][k]);
            if (d > sum) a = i, b = j, d = sum;
        }
    }

    cout << a + 1 << ' ' << b + 1 << ' ' << d << '\n';
}