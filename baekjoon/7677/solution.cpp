#include <bits/stdc++.h>
using namespace std;
const int mod = 1e4;

typedef struct Mat {
    int v[2][2] = {{0, 0}, {0, 0}};
    Mat operator*(const Mat &o) {
        Mat res;
        for (int i = 0; i < 2; i++) {
            for (int k = 0; k < 2; k++) {
                for (int j = 0; j < 2; j++) {
                    res.v[i][j] = (res.v[i][j] + v[i][k] * o.v[k][j]) % mod;
                }
            }
        }
        return res;
    }
} mat_t;


mat_t exp(const Mat &m, int e) {
    if (e == 1) return m;
    mat_t t = exp(m, e / 2);
    if (e & 1) return t * t * m;
    return t * t;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    mat_t m1;
    m1.v[0][0] = m1.v[0][1] = m1.v[1][0] = 1;
    while (true) {
        int n; cin >> n;
        if (n < 0) break;
        if (n == 0) cout << 0 << '\n';
        else cout << exp(m1, n).v[0][1] << '\n';
    }
}