#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int r, c, zr, zc;
    cin >> r >> c >> zr >> zc;
    vector<string> s(r);
    for (auto &s: s) cin >> s;
    vector<string> z(r * zr, string(c * zc, ' '));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int ii = 0; ii < zr; ii++) {
                for (int jj = 0; jj < zc; jj++) z[i * zr + ii][j * zc + jj] = s[i][j];
            }
        }
    }
    for (auto &z: z) cout << z << '\n';
}