#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll inf = 1e18;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> h(n, vector<int>(n));
        vector<int> a(n), b(n);
        for (auto &h: h) {
            for (int &h: h) cin >> h;
        }
        for (int &a: a) cin >> a;
        for (int &b: b) cin >> b;

        ll ans = 0;
        vector<vector<ll>> cst(n, vector<ll>(2, inf));
        cst[0][0] = 0;
        cst[0][1] = a[0];
        for (int i = 1; i < n; i++) {
            bool same = false, pg = false, ng = false;
            for (int j = 0; j < n; j++) {
                if (h[i - 1][j] == h[i][j]) same = true;
                else if (h[i - 1][j] == h[i][j] + 1) pg = true;
                else if (h[i - 1][j] + 1 == h[i][j]) ng = true;
            }
            if (!same) cst[i][0] = min(cst[i][0], cst[i - 1][0]);
            if (!ng) cst[i][0] = min(cst[i][0], cst[i - 1][1]);
            if (!pg) cst[i][1] = min(cst[i][1], cst[i - 1][0] + a[i]);
            if (!same) cst[i][1] = min(cst[i][1], cst[i - 1][1] + a[i]);
        }
        ans += min(cst[n - 1][0], cst[n - 1][1]);

        for (int i = 0; i < n; i++) cst[i][0] = cst[i][1] = inf;
        cst[0][0] = 0;
        cst[0][1] = b[0];
        for (int i = 1; i < n; i++) {
            bool same = false, pg = false, ng = false;
            for (int j = 0; j < n; j++) {
                if (h[j][i - 1] == h[j][i]) same = true;
                else if (h[j][i - 1] == h[j][i] + 1) pg = true;
                else if (h[j][i - 1] + 1 == h[j][i]) ng = true;
            }
            if (!same) cst[i][0] = min(cst[i][0], cst[i - 1][0]);
            if (!ng) cst[i][0] = min(cst[i][0], cst[i - 1][1]);
            if (!pg) cst[i][1] = min(cst[i][1], cst[i - 1][0] + b[i]);
            if (!same) cst[i][1] = min(cst[i][1], cst[i - 1][1] + b[i]);
        }
        ans += min(cst[n - 1][0], cst[n - 1][1]);

        cout << (ans >= inf ? -1 : ans) << '\n';
    }
}