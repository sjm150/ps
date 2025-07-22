#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef unsigned long long ll;
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int p, c;
        cin >> p >> c;
        vector<ll> s(p);
        for (ll &s: s) cin >> s;

        ll l = *min_element(s.begin(), s.end()), r = accumulate(s.begin(), s.end(), 0ll) / c + 1;
        while (l < r) {
            ll m = (l + r) / 2;
            ll sum = 0;
            for (ll s: s) sum += min(s, m);
            if (sum / c < m) r = m;
            else l = m + 1;
        }

        cout << "Case #" << tc << ": " << r - 1 << '\n';
    }
}