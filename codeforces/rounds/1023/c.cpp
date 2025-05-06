#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll inf = 2e12;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll k; cin >> k;
        string s; cin >> s;
        vector<ll> a(n);
        for (ll &a: a) cin >> a;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') a[i] = -inf;
        }

        vector<ll> rmx(n), lmx(n);
        rmx[0] = a[0], lmx[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++) rmx[i] = a[i] + max(0ll, rmx[i - 1]);
        for (int i = n - 2; i >= 0; i--) lmx[i] = a[i] + max(0ll, lmx[i + 1]);

        ll mx = *max_element(lmx.begin(), lmx.end());
        if (mx == k) {
            cout << "YES\n";
            for (ll a: a) cout << a << ' ';
            cout << '\n';
            continue;
        } else if (mx > k) {
            cout << "NO\n";
            continue;
        }

        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') continue;
            ll v = k - max(0ll, i == 0 ? 0 : rmx[i - 1]) - max(0ll, i == n - 1 ? 0 : lmx[i + 1]);
            ok = true;
            a[i] = v;
            break;
        }

        if (ok) {
            cout << "YES\n";
            for (ll a: a) cout << a << ' ';
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}