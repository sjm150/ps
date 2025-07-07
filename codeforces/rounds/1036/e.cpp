#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll &a: a) cin >> a;

        vector<ll> pref(n);
        pref[0] = a[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];
        if (pref[n - 1] % 2) {
            cout << -1 << '\n';
            continue;
        }

        vector<vector<ll>> ans;
        function<bool(int, ll)> solve = [&](int sz, ll req) {
            vector<ll> b(n, 0);
            int idx = lower_bound(pref.begin(), pref.begin() + sz, req / 2) - pref.begin();
            if (idx >= sz - 1) return false;
            if (pref[idx] >= req / 2 && pref[sz - 1] - pref[idx] >= req / 2) {
                ll rem = req / 2;
                for (int i = 0; i <= idx && rem; i++) {
                    if (rem > a[i]) b[i] = a[i];
                    else b[i] = rem;
                    rem -= b[i];
                    a[i] -= b[i];
                }
                rem = req / 2;
                for (int i = idx + 1; i < sz && rem; i++) {
                    if (rem > a[i]) b[i] = a[i];
                    else b[i] = rem;
                    rem -= b[i];
                    a[i] -= b[i];
                }
                ans.push_back(b);
                return true;
            } else {
                if (solve(idx + 1, pref[idx] * 2 - pref[sz - 1])) {
                    ans.push_back(a);
                    return true;
                } else {
                    return false;
                }
            }
        };

        if (solve(n, pref[n - 1])) {
            cout << ans.size() << '\n';
            for (auto &b: ans) {
                for (ll b: b) cout << b << ' ';
                cout << '\n';
            }
        } else {
            cout << -1 << '\n';
        }
    }
}