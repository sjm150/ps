#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string s; cin >> s;
        vector<vector<ll>> a(n, vector<ll>(m));
        for (auto &a: a) {
            for (ll &a: a) cin >> a;
        }

        int sz = n + m;
        vector<ll> sum(sz, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) sum[i] += a[i][j];
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) sum[n + j] += a[i][j];
        }

        int x = 0, y = 0;
        for (char c: s) {
            if (c == 'D') {
                a[x][y] = -sum[x];
                sum[n + y] += a[x][y];
                x++;
            } else {
                a[x][y] = -sum[n + y];
                sum[x] += a[x][y];
                y++;
            }
        }
        a[x][y] = -sum[x];

        for (auto &a: a) {
            for (ll a: a) cout << a << ' ';
            cout << '\n';
        }
    }
}