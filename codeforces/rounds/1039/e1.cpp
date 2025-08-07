#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        auto get = [&](int v) {
            vector<int> pref(n + 1), rmx(n + 1);
            pref[0] = 0;
            for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + (a[i - 1] < v ? -1 : 1);
            rmx[n] = n;
            for (int i = n - 1; i >= 0; i--) rmx[i] = pref[i] > pref[rmx[i + 1]] ? i : rmx[i + 1];
            for (int i = n - k; i >= 0; i--) {
                if (pref[rmx[i + k]] >= pref[i]) return make_pair(i + 1, rmx[i + k]);
            }
            return make_pair(-1, -1);
        };
        int l = 1, r = *max_element(a.begin(), a.end()) + 1;
        while (l < r) {
            int m = (l + r) / 2;
            auto [s, e] = get(m);
            if (s < 0) r = m;
            else l = m + 1;
        }

        int v = r - 1;
        auto [s, e] = get(v);
        cout << v << ' ' << s << ' ' << e << '\n';
    }
}