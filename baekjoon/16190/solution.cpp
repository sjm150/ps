#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n;
    cin >> n;
    int sz = 2 * n;
    vector<int> a(sz);
    for (int &a: a) cin >> a;
    int x;
    cin >> x;

    vector<pair<int, int>> ah;
    int pa = a[0], ph = 0, xh = 0;
    for (int i = 0; i < sz; i++) {
        if (a[i] >= x) break;
        if (i % 2) {
            ph += a[i] - pa;
            pa = a[i];
            xh = ph - x + pa;
            ah.emplace_back(pa, ph);
        } else {
            ph -= a[i] - pa;
            pa = a[i];
            xh = ph + x - pa;
        }
    }

    ll ans = 0;
    for (auto [a, h]: ah) ans = max(ans, (ll(x) * h - ll(a) * xh + x - a - 1) / (x - a));
    cout << ans << '\n';
}