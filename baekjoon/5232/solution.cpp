#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll inf = 1e18;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        vector<vector<vector<vector<ll>>>> cache(n, vector<vector<vector<ll>>>(n, vector<vector<ll>>(5, vector<ll>(5, -inf))));
        function<ll(int, int, int, int)> mxs = [&](int l, int r, int pp, int p) {
            if (l == r) return ll(a[l]);
            ll &mx = cache[l][r][pp + 2][p + 2];
            if (mx > -inf) return mx;
            if (pp != -2) mx = max(mx, a[l] - mxs(l + 1, r, p < 0 ? 0 : p, pp == -1 ? -2 : -1));
            if (pp != 2) mx = max(mx, a[r] - mxs(l, r - 1, p > 0 ? 0 : p, pp == 1 ? 2 : 1));
            return mx;
        };
        cout << (mxs(0, n - 1, 0, 0) >= 0 ? "YES\n" : "NO\n");
    }
}