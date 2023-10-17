#include <bits/stdc++.h>
using namespace std;

int sz[500][500];
int cst[500][500];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> sz[i][i];
            cst[i][i] = 0;
        }
        for (int l = 2; l <= k; l++) {
            for (int i = 0; i + l - 1 < k; i++) {
                int j = i + l - 1;
                cst[i][j] = cst[i][i] + cst[i + 1][j] + sz[i][i] + sz[i + 1][j];
                sz[i][j] = sz[i][i] + sz[i + 1][j];
                for (int k = i + 1; k < j; k++) {
                    int c = cst[i][k] + cst[k + 1][j] + sz[i][k] + sz[k + 1][j];
                    if (cst[i][j] > c) {
                        cst[i][j] = c;
                        sz[i][j] = sz[i][k] + sz[k + 1][j];
                    }
                }
            }
        }
        cout << cst[0][k - 1] << '\n';
    }
}