#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    function<int(int, int)> gcd = [&](int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    for (;;) {
        int r, c; cin >> r >> c;
        if (r == 0) break;
        vector<vector<int>> mat(r, vector<int>(c));
        for (auto &m: mat) {
            for (int &m: m) cin >> m;
        }

        int cnt = 0;
        for (int p = 1; p <= r; p++) {
            if (r % p) continue;
            int n = r / p;
            for (int q = 1; q <= c; q++) {
                if (c % q) continue;
                int m = c / q;
                if ((p == 1 && q == 1) || (n == 1 && m == 1)) continue;

                vector<vector<int>> a(p, vector<int>(q)), b(n, vector<int>(m));
                int ag = 0, bg = 0;
                for (int i = 0; i < p; i++) {
                    for (int j = 0; j < q; j++) {
                        a[i][j] = mat[i][j];
                        ag = gcd(a[i][j], ag);
                    }
                }
                for (auto &a: a) {
                    for (int &a: a) a /= ag;
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        b[i][j] = mat[i * p][j * q];
                        bg = gcd(b[i][j], bg);
                    }
                }
                for (auto &b: b) {
                    for (int &b: b) b /= bg;
                }

                if (mat[0][0] % (a[0][0] * b[0][0])) continue;
                int g = mat[0][0] / a[0][0] / b[0][0];

                bool poss = true;
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if (mat[i][j] != a[i % p][j % q] * b[i / p][j / q] * g) {
                            poss = false;
                            break;
                        }
                    }
                    if (!poss) break;
                }
                if (!poss) continue;

                for (int i = 1; i * i <= g; i++) {
                    if (g % i == 0) {
                        if (g / i == i) cnt++;
                        else cnt += 2;
                    }
                }
            }
        }

        cout << cnt << '\n';
    }
}