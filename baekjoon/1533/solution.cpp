#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000003;

vector<vector<int>> matmul(vector<vector<int>>& a, vector<vector<int>>& b) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = (ll(a[i][k]) * b[k][j] + res[i][j]) % mod;
            }
        }
    }
    return res;
}

vector<vector<int>> matexp(vector<vector<int>>& m, int e) {
    if (e == 1) return m;
    auto tmp = matexp(m, e / 2);
    auto tsqr = matmul(tmp, tmp);
    if (e % 2) return matmul(tsqr, m);
    else return tsqr;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, s, e, t; cin >> n >> s >> e >> t;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int maxt = 1;
    for (auto& s: grid) {
        for (char c: s) maxt = max(maxt, c - '0');
    }

    vector<vector<int>> conn(maxt * n, vector<int>(maxt * n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t = grid[i][j] - '0';
            if (t == 0) continue;
            int k = maxt * i;
            for (; k < maxt * i + t - 1; k++) conn[k][k + 1] = 1;
            conn[k][j * maxt] = 1;
        }
    }

    cout << matexp(conn, t)[(s - 1) * maxt][(e - 1) * maxt] << '\n';
}