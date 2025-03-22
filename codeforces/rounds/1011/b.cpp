#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        vector<pair<int, int>> ans;
        int sz = 0;
        bool z = false;
        for (int i = n / 2; i < n; i++) {
            if (a[i] == 0) {
                z = true;
                break;
            }
        }
        if (z) {
            ans.emplace_back(n / 2 + 1, n);
            sz += 1;
        } else {
            sz += n - n / 2;
        }

        z = false;
        for (int i = 0; i < n / 2; i++) {
            if (a[i] == 0) {
                z = true;
                break;
            }
        }
        if (z) {
            ans.emplace_back(1, n / 2);
            sz += 1;
        } else {
            sz += n / 2;
        }

        ans.emplace_back(1, sz);
        cout << ans.size() << '\n';
        for (auto [l, r]: ans) cout << l << ' ' << r << '\n';
    }
}