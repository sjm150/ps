#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;

    int n; cin >> n;
    vector<int> a(n), s(n);
    for (int &a: a) cin >> a;
    s[0] = a[0];
    for (int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];
    vector<ll> ss(n);
    ss[0] = s[0];
    for (int i = 1; i < n; i++) ss[i] = ss[i - 1] + s[i];

    auto calc = [&](int a, int b, int e) {
        return ss[e] - (b ? ss[b - 1] : 0) - (a ? s[a - 1] : 0) * ll(e - b + 1);
    };
    vector<ll> bsum(n), bss(n);
    for (int i = 0; i < n; i++) bsum[i] = calc(i, i, n - 1);
    bss[0] = bsum[0];
    for (int i = 1; i < n; i++) bss[i] = bss[i - 1] + bsum[i];

    vector<ll> bse(n);
    bse[0] = n;
    for (int i = 1; i < n; i++) bse[i] = bse[i - 1] + n - i;
    auto idx = [&](ll i) {
        auto it = upper_bound(bse.begin(), bse.end(), i);
        int b = it - bse.begin();
        return pair<int, int>(b, b + i - (it == bse.begin() ? 0 : *prev(it)));
    };

    int q; cin >> q;
    while (q--) {
        ll l, r; cin >> l >> r;
        auto [la, lb] = idx(l - 1);
        auto [ra, rb] = idx(r - 1);
        if (la == ra) cout << calc(la, lb, rb) << '\n';
        else cout << (calc(la, lb, n - 1)) + bss[ra - 1] - bss[la] + (calc(ra, ra, rb)) << '\n';
    }
}