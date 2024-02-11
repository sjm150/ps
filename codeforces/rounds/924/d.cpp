#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(vector<int>& c, int k, int b, int x) {
    ll ret = -ll(k - 1) * x;
    for (int c: c) {
        int q = (c + k - 1) / k;
        int r = q * k - c;
        ret += (ll(k - r) * q * (c - q) + ll(r) * (q - 1) * (c - q + 1)) / 2 * b;
    }
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, b, x; cin >> n >> b >> x;
        vector<int> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];

        int maxc = 0;
        for (int c: c) maxc = max(maxc, c);

        int l = 1, r = maxc + 1;
        while (r - l >= 3) {
            int lm = l + (r - l) / 3;
            int rm = r - (r - l) / 3;
            if (f(c, lm, b, x) < f(c, rm, b, x)) l = lm;
            else r = rm;
        }

        cout << max(max(f(c, l, b, x), f(c, r, b, x)), f(c, (l + r) / 2, b, x)) << '\n';
    }
}