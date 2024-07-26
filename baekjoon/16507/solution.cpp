#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int r, c, q; cin >> r >> c >> q;
    vector<vector<int>> k(r, vector<int>(c));
    for (auto &k: k) {
        for (int &k: k) cin >> k;
    }
    vector<vector<int>> sumk(r + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            sumk[i][j] = sumk[i - 1][j] - sumk[i - 1][j - 1] + sumk[i][j - 1] + k[i - 1][j - 1];
        }
    }
    while (q--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        cout << (sumk[r2][c2] - sumk[r2][c1 - 1] - sumk[r1 - 1][c2] + sumk[r1 - 1][c1 - 1]) / (r2 - r1 + 1) / (c2 - c1 + 1) << '\n';
    }
}