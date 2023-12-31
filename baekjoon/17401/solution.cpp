#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> mat_t;
const int mod = 1e9 + 7;

mat_t zeromat(int n) { return mat_t(n, vector<int>(n, 0)); }

mat_t idmat(int n) {
    mat_t mat = zeromat(n);
    for (int i = 0; i < n; i++) mat[i][i] = 1;
    return mat;
}

mat_t matmul(mat_t& a, mat_t& b) {
    int n = a.size();
    mat_t c = zeromat(n);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = (c[i][j] + ll(a[i][k]) * b[k][j]) % mod;
            }
        }
    }
    return c;
}

mat_t matpow(mat_t& m, int e) {
    if (e == 0) return idmat(m.size());
    mat_t t = matpow(m, e / 2);
    t = matmul(t, t);
    if (e & 1) t = matmul(t, m);
    return t;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t, n, d; cin >> t >> n >> d;
    int q = d / t, r = d % t;
    mat_t tmat = idmat(n), rmat = idmat(n);
    for (int i = 0; i < t; i++) {
        int m; cin >> m;
        mat_t mat = zeromat(n);
        while (m--) {
            int a, b, c; cin >> a >> b >> c;
            mat[a - 1][b - 1] = c;
        }
        tmat = matmul(tmat, mat);
        if (i == r - 1) rmat = tmat;
    }

    mat_t res = matpow(tmat, q);
    if (r) res = matmul(res, rmat);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << res[i][j] << ' ';
        cout << '\n';
    }
}