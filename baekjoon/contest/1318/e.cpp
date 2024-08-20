#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &a: a) cin >> a;
    auto val = [&](int i) {
        ll mx = 0;
        for (int j = 0; j < n; j++) mx = max(mx, abs(i - j) * a[j]);
        return mx;
    };
    int l = 0, r = n - 1;
    while (l + 2 < r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (val(m1) < val(m2)) r = m2;
        else l = m1;
    }
    cout << min(min(val(l), val(min(n - 1, l + 1))), min(val(max(0, r - 1)), val(r))) << '\n';
}